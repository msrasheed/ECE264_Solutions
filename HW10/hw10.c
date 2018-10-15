#include "hw10.h"
//modify the main() function
#ifdef TEST_MAINFUNC

int main(int argc, char **argv){
  // check the arguments
  if (argc != 3)
  {
    fprintf(stderr, "Wrong arguments\n");
    return EXIT_FAILURE;
  }
  // check radius and epsilon values

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
    return EXIT_FAILURE;
  }

  // call adaptive threshold function
  // check for errors after calling adaptive threshold
	// write the adaptive threshold image to file
  if (BMP_Write(argv[2], gray_image) == 0)
  {
    fprintf(stderr, "Error in writing image\n");
    return EXIT_FAILURE;
  }
	// free all the images
  BMP_Free(image);
  BMP_Free(gray_image);

	return EXIT_SUCCESS;
}

#endif
