#include "hw11.h"
//Modify this file
#ifdef TEST_MAIN

int main(int argc, char **argv){
  // check the arguments
	if (argc != 5)
  	{
	    fprintf(stderr, "Wrong arguments\n");
	    return EXIT_FAILURE;
  	}
  // check radius and epsilon values
  	int radius = (int) strtol(argv[3], NULL, 10);
  	int epsilon = (int) strtol(argv[4], NULL, 10);

  // open the BMP file
  	BMPImage * image = BMP_Open(argv[1]);
	if (image == NULL) 
	{
		fprintf(stderr, "Error opening BMP file\n");
		return EXIT_FAILURE;
	}
  // convert to gray scale
	BMPImage * gray_image = ImgToGray(image);
	// check for error in converting to gray scale
	if (gray_image == NULL)
	{
		fprintf(stderr, "Failed to create gray image \n");
		BMP_Free(image);
		return EXIT_FAILURE;
	}

  // call adaptive threshold function
	BMPImage * adaptImage = AdaptiveThresholding(gray_image, radius, epsilon);
  // check for errors after calling adaptive threshold
	if (adaptImage == NULL) 
	{
		fprintf(stderr, "Failed to create adaptive threshold image\n");
		BMP_Free(image);
		BMP_Free(gray_image);
		return EXIT_FAILURE;
	}
	// write the adaptive threshold image to file
	if (BMP_Write(argv[2], adaptImage) == 0)
	{
		fprintf(stderr, "Error in writing image\n");
		BMP_Free(image);
		BMP_Free(gray_image);
		BMP_Free(adaptImage);
		return EXIT_FAILURE;
	}
	// free all the images
	BMP_Free(image);
	BMP_Free(gray_image);
	BMP_Free(adaptImage);

	return EXIT_SUCCESS;
}

#endif
