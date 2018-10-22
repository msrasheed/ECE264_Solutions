#include "bmpfunc.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifdef TEST_FUNCGIVEN

int RGB2Gray(unsigned char red, unsigned char green, unsigned char blue){
	// this is a commonly used formula
	int gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
	return gray;
}

#endif

//Modify below this line and use code from HW10 for IMGTOGRAY()

#ifdef TEST_IMGTOGRAY

BMPImage * ImgToGray(BMPImage * image){
	// use code from your HW10
	int width = (image->header).width;
	int height = (image->header).height;

	// allocate space for the image
	// the image has the same size
	// therefore the header has to stay the same
	// check for memory allocation failure 
	BMPImage * gray_image = malloc(sizeof(BMPImage));
	if (gray_image == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for gray BMPImage\n");
		return NULL;
	}
	
	//gray_image can be the name of the new image memory allotment
	//gray_image->header = image->header;
	gray_image->header = image->header;
	
	//Assign the the imagesize as height * width
	// (gray_image->header).imagesize = (gray_image->header).width*(gray_image->header).height;
	(gray_image->header).imagesize = width * height * (gray_image->header).bits / 8;
	
	//check for data allocation failure using :
	//(gray_image->data = malloc(sizeof(unsigned char)*(gray_image->header).imagesize)) == NULL)
	gray_image->data = malloc(sizeof(unsigned char) * (gray_image->header).imagesize);
	if (gray_image->data == NULL) 
	{
		fprintf(stderr, "Failed to allocate memory for gray image data\n");
		return NULL;
	}
	
	int pixel=0;
	//Run loop for all pixels using height and width
	//convert each pixel of all channels to gray using the given RGB2GRAY function
	// gray_val = RGB2Gray(image -> data[pixel+2],image -> data[pixel + 1],	image -> data[pixel]);
	//assign values to all pixels of gray_image for each channel
	//gray_image->data[pixel+2] = gray_val;
	//gray_image->data[pixel+1] = gray_val;
	//gray_image->data[pixel] = gray_val;
	//pixel+=3 to move on to the next 3 channel combination
	for (pixel = 0; pixel < width * height * 3; pixel += 3) 
	{
		int gray_val = RGB2Gray(image->data[pixel+2], image->data[pixel+1], image->data[pixel]);
		gray_image->data[pixel+2] = gray_val;
		gray_image->data[pixel+1] = gray_val;
		gray_image->data[pixel] = gray_val;
	}
		
	//return the result
	return gray_image;
}

#endif

//Write your own code for Adaptive Thresholding Function
#ifdef TEST_ADAPTIVETHRESHOLDING

BMPImage * AdaptiveThresholding(BMPImage * grayImage, int radius, int epsilon){
 	// allocate space for the image
 	BMPImage * adaptive = malloc(sizeof(BMPImage));
	// the image has the same size(height and width)
	// therefore the header has to stay the same

	adaptive->header = grayImage->header;
	// (gray_image->header).imagesize = (gray_image->header).width*(gray_image->header).height;
	if ((adaptive->data = malloc(sizeof(unsigned char)*(adaptive->header).imagesize)) == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		free(adaptive);
		return NULL;
	}

	int pixel=0;
	//Run a nested loop for all elements using height and width
	int width = (adaptive->header).width;
	int height = (adaptive->header).height;
	int row;
	int col;
	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{
	        //Find the maximum of top row, bottom rpw, left column and right column using radius
		/*int toprow = MAX(0, row-radius);
	     	 int bottomrow = MIN(height-1, row+radius);
	     	 int leftcol = MAX(0, col-radius);
	     	 int rightcol = MIN(width-1, col+radius);*/
			int toprow = MAX(0, row-radius);
			int bottomrow = MIN(height-1, row+radius);
			int leftcol = MAX(0, col-radius);
			int rightcol = MIN(width-1, col+radius);
	    	//Calculate the avergage of all pixels
		//Run loop from toprow to bottom row
		//Inside which run a loop from left column to right column
			int row2;
			int col2;
			int value =  0;
			int counter = 0;
			for (row2 = toprow; row2 <= bottomrow; row2++)
			{
				for (col2 = leftcol; col2 <= rightcol; col2++)
				{
			//calculate the location of each pixel using (row2*width + col2)*3;
	         	//add all data values at every location point in data
					value += grayImage->data[(row2*width + col2)*3];
			//keep a counter for averaging
					counter++;
				}
			}
			pixel = (row*width + col) * 3;
		//Outside the second nested loop: 
		//calculate averge (using int)
			int average = value / counter;
		//check if average-epsilon is greater than grayImage->data[at that pixel point]
			if (average - epsilon > grayImage->data[pixel])
			{
				//then assign adaptive thresholding image data as 0(black) for data value at pixel, pixel+1, pixel+2
				adaptive->data[pixel] = 0;
				adaptive->data[pixel + 1] = 0;
				adaptive->data[pixel + 2] = 0;
			} // else if average is lower then color shall be white(255) for data value at pixel, pixel+1, pixel+2
			else if (average - epsilon <= grayImage->data[(row*width + col)*3])
			{
				adaptive->data[pixel] = 255;
				adaptive->data[pixel + 1] = 255;
				adaptive->data[pixel + 2] = 255;
			}
		}
	}
	//return the image after adaptive thresholding
	return adaptive;
}


#endif
