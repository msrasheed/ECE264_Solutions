/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw15.h"

#ifdef LINKEDLIST
// Do not modify this function.
void LinkedListPrint(Node * head)
{

	Node *temp = head;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d\n",temp->value);
		}
		temp=temp->next;
	}
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
{
	/*
	Create a new Node with `value` set to `val`. Set `next` to NULL.
	*/
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

void LinkedListCreate(Node ** head, char* name)
{
	/*
	Create a linked list from the input file referenced by `name`.
	*/
	Node * h = NULL;
	FILE * fptr = fopen(name, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "file failed to open \n");
		return;
	}
	int a;
	fscanf(fptr, "%d", &a);
	h = CreateNode(a);
	Node * n = h;
	while (fscanf(fptr, "%d", &a) == 1)
	{
		n->next = CreateNode(a);
		n = n->next;
	}
	fclose(fptr);
	*head = h;
}
#endif
#ifdef TEST_REMOVED
//This function will remove repetitions of a linked list value.

void RemoveDuplicate(Node *headRef)
{
	/*
	This function will remove repetitions from the linked list referenced by headRef.
	Each time we check for a new Node in the linked list, we will check if it is distinct from
	the Nodes already present in the list ( upto the previous Node).
	So for each occurrence after its first, we will be deleting that node.
	To delete a node: we will map the next Node of the previous Node to the Node after the current Node.
	Print the linked list after all repetitions have been removed. Use the function given to you for priniting.
	*/
	Node * p = headRef;
	Node * n = p->next;
	while(n != NULL)
	{
		Node * iter = headRef;
		Node * prevN = n;
		while (iter != n)
		{
			if (iter->value == n->value)
			{
				p->next = n->next;
				free(n);
				n = p->next;
				iter = n;
			}
			else
			{
				iter = iter->next;
			}
		}
		if (prevN == n)
		{
			p = p->next;
			n = p->next;
		}
	}
}
#endif
