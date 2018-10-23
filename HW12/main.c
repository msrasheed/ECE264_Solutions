/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw12.h"



/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc < 4 then return EXIT_FAILURE
	if (argc < 4)
	{
		fprintf(stderr, "Need four 3 arguments, entered %d\n", argc-1);
		return EXIT_FAILURE;
	}
	// argv[1] - length of linked list
	int length = (int) strtol(argv[1], NULL, 10);
	// argv[2] - value of k as mentioned in josephus algorithm
	int k = (int) strtol(argv[2], NULL, 10);
	// argv[3] - value of elemDivisible
	int elemDivisible = (int) strtol(argv[3], NULL, 10);
	// create head node
	Node * head = NULL;
	// create Linked list with length as argv[1]
	LinkedListCreate(&head, length);
	// run josephus
	Josephus(&head, k, elemDivisible);
	// free the head node
	free(head);
	return EXIT_SUCCESS;
}

#endif
