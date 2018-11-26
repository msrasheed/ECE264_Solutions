// Edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"


#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
	// check for input error
	if (argc < 2) 
	{
		fprintf(stderr, "Not enough input arguments\n");
		return EXIT_FAILURE;
	}
	// open the file
	// input file is in argv[1]
	FILE * fptr = fopen(argv[1], "r");
	// n is the element in the file
	int n;
	fscanf(fptr, "%d", &n);
	// dim is the second element in the file
	int dim;
	fscanf(fptr, "%d", &dim);
	// the rest of the data in the file are the datapoints.
	// call LinkedListCreate
	ListNode * head;
	LinkedListCreate(&head, n, dim, fptr);
	fclose(fptr);
	// call FindMin
	FindMin(head);

	while (head != NULL)
	{
		ListNode * node = head->next;
		free(head->treenode->data);
		free(head->treenode);
		free(head);
		head = node;
	}
	return EXIT_SUCCESS;
}
#endif
