/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw12.h"

#ifdef LINKEDLIST

// Do not modify the below program, we are using ifdef block for
// ease of grading. Please include this flag in your Makefile
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
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");

}
#endif


/********** Do Not modify the file above this line, you should modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int value)
{
	// allocate memory for the new Node*
	Node * p = malloc(sizeof(Node));
	// check memory allocation fails
	if (p == NULL)
	{
		fprintf(stderr, "Memory allocation for node failed\n");
		return NULL;
	}
	// create a Node* with the value as 'value'(input argument).
	p->value = value;
	return p;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
// 1. head: the head of the singly linkedlist.
// 2. length: the length of the singly linkedlist.

// This function creates and initializes a singly linkedlist with length as 'length'(input argument),
// The values of the nodes within the singly linkedlist will be the same as array indddices.
// For example, if the singly linkedlist length is 4, the value of the nodes will be 0 1 2 3
void LinkedListCreate(Node * * head, int length)
{
	// check if length is not negative
	if (length < 0)
	{
		fprintf(stderr, "length is not positive\n");
		return;
	}
	// create linked list of length as 'length'
	// do not return anything
	Node * p = NULL;
	Node * n = NULL;
	int i;
	for (i = length - 1; i >= 0; i--)
	{
		p = CreateNode(i);
		p->value = i;
		p->next = n;
		n = p;
	}

	*head = p;
}
#endif



#ifdef TEST_JOSEPHUS

// 1. head: the head of the singly linkedlist.
// 2. k : this variable will be used for counting if count = k, the element will be out.
// 3. elemDivisible : this variable will be used for printing. When the number of
//    remaining nodes in linked list is divisible by elemDivisible then you should 
//    print the remaining LinkedList with print functin provided to you.

// This function should solve the josephus problem using the singly linkedlist.

void Josephus(Node ** head, int k, int elemDivisible)
{
	// implement the algorithm here
	// remember to free the memory of the nodes
	// print the linked list using our function when number of nodes remaining is divisible by elemDivisible
	Node * p = *head;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}

	int duck = 0;
	Node * n = NULL;
	p = *head; 

	while (count != 1)
	{
		n = p;
		p = p->next;
		if (p == NULL)
		{
			p = *head;
		}
		duck++;
		if (duck == k)
		{
			if (n->next == NULL)
			{
				*head = p->next;
				free(p);
				p = *head;
			} 
			else 
			{
				n->next = p->next;
				free(p);
				p = n->next;
				if (p == NULL)
				{
					p = *head;
				}
			}
			count--;
			duck = 0;
			if (count % elemDivisible == 0)
			{
				LinkedListPrint(*head);
			}
		}
	}
}

#endif
