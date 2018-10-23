/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw13.h"

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


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
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
//head: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

//This function will create and initialize the singly linkedlist with length=len,

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// This function is similar to the one in HW12.
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
// source is the Node corresponding to the head of the list
// head1 is the list corresponding upper half of the list. (After Partition)
// head2 is the list corresponding lower half of the list. (After Partition)
void SpiltList(Node* source, Node** head1, Node** head2) 
{ 
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


#ifdef TEST_DIV
void Divide(Node** source) 
{ 
	// Declare a node, to hold the current head of source list.
	Node * head = *source;
	// Declare nodes, to hold the two the heads of the two sub-lists.
	Node * head1 = NULL;
	Node * head2 = NULL;
  
	// Check for the base case -- length 0 or 1
	if (head->next == NULL)
	{
		// if so, return;
		free(head);
		return;
	}
	 
	// Use SpiltList(...) to partition the list into sub lists.
	SpiltList(head, &head1, &head2);
	// Use LinkedListPrint(...); to print the upper sub-list.
	LinkedListPrint(&head1);
	// Use LinkedListPrint(...); to print the lower sub-list
	LinkedListPrint(&head2);
		// DO NOT USE YOUR OWN PRINT FUNCTION.
	
	 // Recursively Divide(...) both sub-lists, to find their respective mid-points
	 // till only one or no elements are left in the sub-lists.
	Divide(&head1);
	Divide(&head2);
} 
#endif

