/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw13.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	if (argc < 2)
	{
		fprintf(stderr, "not enough input arguments\n");
		return EXIT_FAILURE;
	}
	// input file is specified through the Makefile.

	// open file to read
	FILE * fptr = fopen(argv[1], "r");
	// check for fopen fail. If so, return EXIT_FAILURE
	if (fptr == NULL)
	{
		fprintf(stderr, "File failed to open\n");
		return EXIT_FAILURE;
	}
	// count the number of integers in the file.
	int count = 0;
	int a;
	while (fscanf(fptr, "%d", &a) == 1)
	{
		count++;
	}
	// allocate memory to store the numbers
	int * arr = malloc(sizeof(int) * count);
	// check for malloc fail, if so, return EXIT_FAILURE
	if (arr == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for arr\n");
		return EXIT_FAILURE;
	}
	// use fscanf to read the file, and store its contents into an array.
	fseek(fptr, 0, SEEK_SET);
	int i;
	for (i = 0; i < count; i++)
	{
		fscanf(fptr, "%d", &arr[i]);
	}
	fclose(fptr);
	// create head node to store the head of the linked list.
	Node * head = NULL;
	// call the appropriate function to create the rest of the linked list, with the values of the array.
	LinkedListCreate(&head, count, arr);
	// Divide is a function to break the lists into smaller sublists.
		// You are supposed to find the mid-point of the list, and then break the list into two lists.
		// Then the sub-lists are broken down further into smaller sub-lists.
		// Refer to the example in the README
	Divide(&head);
	// Tip: check for memory errors.
	free(arr);
	return EXIT_SUCCESS;
}

#endif
