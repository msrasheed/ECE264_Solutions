/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw14.h"


#ifdef LINKEDLIST
// Do not modify this function, we are using this within ifdef block for
// ease of grading.
void LinkedListPrint(Node * * source)
{

	Node *temp = * source;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");
}
#endif

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	// input file is specified through the Makefile.
	if (argc < 2)
	{
		fprintf(stderr, "not enough input arguments\n");
		return EXIT_FAILURE;
	}
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
	// use fscanf to read the file for its contents.
	fseek(fptr, 0, SEEK_SET);
	int i;
	for (i = 0; i < count; i++)
	{
		fscanf(fptr, "%d", &arr[i]);
	}
	fclose(fptr);
	// create head node, which corresponds to the head of the linked-list.
	Node * head = NULL;
	// You must now use the appropriate function to construct the remaining list.
	LinkedListCreate(&head, count, arr);
	// call MergerSort() function for final output.
		// This will call a recursive function.
		// The input list will be divided into two sub-lists recursively,
		// Then the contents of the sub-lists are compared and merged back to form the
		// sorted output list.
	MergeSort(&head);
	// use the provided function to print the final list.
	LinkedListPrint(&head);
	// Tip: Check for memory errors.
	free(arr);

	Node * p = head;
	Node * n = p->next;
	while(n != NULL)
	{
		free(p);
		p = n;
		n = n->next;
	}
	free(p);

	return EXIT_SUCCESS;
}

#endif
