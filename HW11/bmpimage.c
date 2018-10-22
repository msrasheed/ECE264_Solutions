#include "bmpimage.h"
//Include your own code from HW10 and modify this file
#ifdef TEST_HEADERVALID

int Is_BMPHeader_Valid(BMPHeader* header, FILE *fptr) {
	// Make sure this is a BMP file
        //Check for header->type
	if (header->type != 0x4D42)
	{
		fprintf(stderr, "Incorrect magic number\n");
		return 0;
	}
	
	// check the offset(header->offset)from beginning of file to image data
	// which is essentially the size of the BMP header
	// known as BMP_HEADER_SIZE for this exercise/assignment
	if (header->offset != BMP_HEADER_SIZE)
	{
		fprintf(stderr, "Incorrect offset\n");
		return 0;
	}

	// check for DIB header size == DIB_HEADER_SIZE
	// For this exercise/assignment
	// use header->DIB_header_size 
	if (header->DIB_header_size != DIB_HEADER_SIZE)
	{
		fprintf(stderr, "Incorrect DIB_header_size\n");
		return 0;
	}
	
	// Make sure there is only one image plane
	//use header->planes
	if (header->planes != 1)
	{
		fprintf(stderr, "Incorrect planes\n");
		return 0;
	}
	
	// Make sure there is no compression
	if (header->compression != 0)
	{
		fprintf(stderr, "Incorrect compression\n");
		return 0;
	}
	
	// ncolours and importantcolours should be 0
	if (header->ncolours != 0 || header->importantcolours != 0)
	{
		fprintf(stderr, "Incorrect ncolours or importantcolours\n");
		return 0;
	}

	// Make sure we are getting 24 bits per pixel
	// or 16 bits per pixel
	// only for this assignment
	if (header->bits != 24 && header->bits != 16)
	{
		fprintf(stderr, "Incorrect bits per pixel\n");
		return 0;
	}
	
	// check for file size, image size
	// based on bits, width, and height
	//check for imagesize using size-offset=imagesize, each element is a part of the header structure, so use -> accordingly
	if (header->imagesize != header->size - header->offset)
	{
		fprintf(stderr, "Incorrect imagesize\n");
		return 0;
	}
	//use ftell(fptr) for file position(file_pos)
	long file_pos = ftell(fptr);
	//check if input file can be read: if (fseek(fptr, 0, SEEK_END) != 0)
	if (fseek(fptr, 0, SEEK_END) != 0)
	{
		fprintf(stderr, "fseek failed\n");
		return 0;
	}
       
	//use ftell(fptr) for file file size(file_size)
	long file_size = ftell(fptr);
	//check (fseek(fptr, file_pos, SEEK_SET) != 0) for input file reading check
	if (fseek(fptr, file_pos, SEEK_SET) != 0)
	{
		fprintf(stderr, "fseek failed second time\n");
		return 0;
	}
	//file_pos = ftell(fptr);

	//check if file_size is not equal to header->size
	if (file_size != header->size)
	{
		fprintf(stderr, "file size measured doesn't equal size in header\n");
		return 0;
	}
	
	//number of rows= width of file * number of bits +31
	//multiply total value by 4
	//check if number of rows*height is the image size
	long rows = header->width * header->bits;
	//rows *= 4;
	if (rows * header->height / 8 != header->imagesize)
	{
		fprintf(stderr, "calculated size doesn't equal heder->size\n");
		return 0;
	}
	return TRUE;
}

#endif

#ifdef TEST_BMPOPENFILE

BMPImage *BMP_Open(const char *filename) {
// use code from HW10
	 //open file
  //read file
	FILE *fptr = fopen(filename,"r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Failed to open input file\n");
		return NULL;
	}

	//Allocate memory for BMPImage*;
	BMPImage *bmpImage = (BMPImage *)malloc(sizeof(BMPImage));

	//check for memory allocation errors
	if (bmpImage == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for image\n");
		return NULL;
	}
	
	//Read the first 54 bytes of the source into the header
	int read_size = fread(&(bmpImage->header), sizeof(BMPHeader), 1, fptr);

	//Compute data size, width, height, and bytes per pixel;
	//check for any error while reading
	if (read_size != 1)
	{
		fprintf(stderr, "Error in reading header\n");
		return NULL;
	}
	
	//check if the header is valid
	if (Is_BMPHeader_Valid(&(bmpImage->header), fptr) != 1)
	{
		fprintf(stderr, "Inocrrect header\n");
		return NULL;
	}
	
	// Allocate memory for image data
	//(bmpImage->data = (unsigned char *)malloc(sizeof(unsigned char)*((int)((bmpImage->header).imagesize))))
	bmpImage->data = malloc(sizeof(unsigned char) * ((bmpImage->header).imagesize));
	//check error
	if (bmpImage->data == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for image data\n");
		return NULL;
	}

	// read in the image data
	long numBytesRead = fread(bmpImage->data, sizeof(unsigned char), (bmpImage->header).imagesize, fptr);

	//check for error while reading
	if (numBytesRead != (bmpImage->header).imagesize)
	{
		fprintf(stderr, "Error in reading image data\n");
		return NULL;
	}
	
	fclose(fptr);
	return bmpImage;
}
#endif


#ifdef TEST_WRITEFUNC

int BMP_Write(const char * outfile, BMPImage* image){
	// use code from HW10
	FILE *fptr = fopen(outfile, "w");
	//open file and check for error
	if (fptr == NULL)
	{
		fprintf(stderr, "Failed to open output file\n");
		return 0;
	}

	//check error for writing
	if (fwrite(&(image->header), sizeof(BMPHeader), 1, fptr) != 1)
	{
		fprintf(stderr, "Error in writing header to file\n");
		return 0;
	}
	
	// write and check for image data:(fwrite(image->data, sizeof(unsigned char), (image->header).imagesize, fptr) != (image->header).imagesize) 
	long numBytesWritten = fwrite(image->data, sizeof(unsigned char), (image->header).imagesize, fptr);
	if (numBytesWritten != (image->header).imagesize)
	{
		fprintf(stderr, "Error in writing image data to file\n");
		return 0;
	}
	
	fclose(fptr);
	return TRUE;
}

#endif



/* The input argument is the BMPImage pointer. The function frees memory of
 * the BMPImage.
 */
#ifdef TEST_BMPFREEFUNC
void BMP_Free(BMPImage* image) {
	//free the data
	if (image != NULL)
	{
		if (image->data != NULL)
		{
			free(image->data);
		}
		free(image);
	}
}

#endif
