/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw14.h"


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	// same as previous homeworks
	// Define a new variable of type Node
	Node * p = malloc(sizeof(Node));
	if (p == NULL)
	{
		fprintf(stderr, "Memory allocation for node failed\n");
		return NULL;
	}
	// Initialize "next", and "value" appropriately 
	p->value = val;
	p->next = NULL;
	//return the newNode
	return p;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
//source: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// Refer HW13 and HW12
	// Tip: use CreateNode(arr[index])
	Node * p = NULL;
	Node * n = NULL;
	int i;
	for (i = len - 1; i >= 0; i--)
	{
		p = CreateNode(arr[i]);
		p->next = n;
		n = p;
	}

	*source = p;
}
#endif


#ifdef TEST_SPLIT
// source is the head of the list to be split.
// head1 is the head of the upper sub-list.
// head2 is the head of the lower sub-list.

void SplitList(Node* source, Node** head1, Node** head2)
{
	// Refer HW13
	// Find the mid point of the list.
	Node * n = source;
	int count = 0;
	while (n != NULL)
	{
		count++;
		n = n->next;
	}
	int mid;
	if (count % 2 == 0)
	{
		//in case of an even number of nodes, mid point will be floor(<num_elements>/2)
			//Example: 1,2,3,4
				// The list should split into 1,2 and 3,4
		mid = count/2;
	}
	else
	{
		//in case of an odd number of nodes, mid point will be <num_elements>/2
			//Example: 1,2,3,4,5
				// The list should split into 1,2,3 and 4,5	
		mid = count/2 + 1;			
	}

	*head1 = source;
	n = source;
	int i;
	for (i = 0; i < mid - 1; i++)
	{
		n = n->next;
	}
	*head2 = n->next;
	n->next = NULL;
    	// Tip: head1 will point to the source node.
	// Tip: head2 will point to the mid-point of the list.
	// Tip: Ensure you break the link between the sub-lists.
} 
#endif

#ifdef TEST_MERGE
// upper is the upper sub-list to be merged
// lower is the lower sub-list to be merged
Node* Merge(Node* upper, Node* lower) 
{ 
	Node * newHead = NULL;
	Node * n;
	// Check for the base cases. (When either sub-list is NULL)
  	while (upper != NULL && lower != NULL)
  	{
	// Pick the larger between upper and lower, and recur appropriately.
  		if (upper->value < lower->value)
  		{
  			if (newHead == NULL)
  			{
  				newHead = upper;
  				n = upper;
  			}
  			else
  			{
  				n->next = upper;
  				n = n->next;
  			}
  			upper = upper->next;
  		}
  		else
  		{
  			if (newHead == NULL)
  			{
  				newHead = lower;
  				n = lower;
  			}
  			else
  			{
  				n->next = lower;
  				n = n->next;
  			}
  			lower = lower->next;
  		}
	}
	if (upper == NULL)
	{
		while (lower != NULL)
		{
			n->next = lower;
			n = n->next;
			lower = lower->next;
		}
	}
	else
	{
		while (upper != NULL)
		{
			n->next = upper;
			n = n->next;
			upper = upper->next;
		}
	}

	n->next = NULL;
	// return the merged array
	return newHead;
} 
#endif

#ifdef TEST_SORT
// source is the head of the list to for which MergeSort is to be performed.
void MergeSort(Node** source) 
{ 
	// Declare a node, to hold the current head of the source list.
	Node * head = *source; 
	// Declare nodes, to hold the two the heads of the two sub-lists.
  	Node * head1 = NULL;
  	Node * head2 = NULL;
	// Check for the base case -- length 0 or 1
		// if so, return;
  	if (head->next == NULL || head == NULL)
  	{
  		return;
  	}
	// Use SpiltList() to partition the list into sub lists.
		// This will partiton the source list, into two lists (As done in the previous homework)
	SplitList(head, &head1, &head2);
	// Recursively sort the sub-lists by calling MergeSort() on the upper and lower sub-lists.
		// MergeSort() is a recursive function, and MergeSort() needs to be called
		// on both sub-lists (obtained after partitioning)
	 MergeSort(&head1);
	 MergeSort(&head2);
	// Merge the two sorted lists together, using the Merge()
	 *source = Merge(head1, head2);
} 
#endif

