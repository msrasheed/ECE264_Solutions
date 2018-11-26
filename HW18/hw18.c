//edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"

//Do Not Change this function
void PrintAnswer(ListNode* head, ListNode* min1, ListNode* min2)
{
	ListNode* temp = head;
	int i;
	while(temp!=NULL)
	{
		i = 0;
		while(i < head -> treenode->dimension)
		{
			if(i == 0)
				printf("(%d, ", temp->treenode->data[i]);
			else if(i == head -> treenode->dimension-1)
				printf("%d)\n", temp->treenode->data[i]);
			else
				printf("%d, ", temp->treenode->data[i]);
			i+=1;

		}
		temp = temp->next;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min1->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d) <-> ", min1->treenode->data[i]);
		else
			printf("%d, ", min1->treenode->data[i]);
		i+=1;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min2->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d)\n", min2->treenode->data[i]);
		else
			printf("%d, ", min2->treenode->data[i]);
		i+=1;
	}
}

/*
YOU CAN EDIT BELOW THIS COMMENT
*/

#ifdef TEST_MIN
void FindMin(ListNode* head)
{
	// find pair of ListNodes with least distance between them.
	// call print Function

	/*
	ENSURE the 2nd parameter of the print function (min1) is smaller than
	the 3rd parameter (min2). 
	Look at README, and expected output for more details.
	*/
	ListNode * sHead = head;
	ListNode * iter = sHead->next;
	ListNode * hold1 = sHead;
	ListNode * hold2 = iter;
	int minDist = FindDist(sHead->treenode, iter->treenode);
	while(sHead != NULL)
	{
		iter = sHead->next;
		while(iter != NULL)
		{
			int dist = FindDist(sHead->treenode, iter->treenode);
			if(dist < minDist)
			{
				minDist = dist;
				hold1 = sHead;
				hold2 = iter;
			}
			iter = iter->next;
		}
		sHead = sHead->next;
	}
	int i = 0;
	while(i < head->treenode->dimension)
	{
		if(hold1->treenode->data[i] < hold2->treenode->data[i])
		{
			sHead = hold1;
			iter = hold2;
			i = head->treenode->dimension;
		}
		else if (hold1->treenode->data[i] > hold2->treenode->data[i])
		{
			sHead = hold2;
			iter = hold1;
			i = head->treenode->dimension;
		}
		i++;
	}
	PrintAnswer(head, sHead, iter);
}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
	//find the eucledian distance between
	// x->data and y->data
	int dist = 0;
	int i;
	for(i = 0; i < x->dimension; i++)
	{
		dist += (x->data[i] - y->data[i]) * (x->data[i] - y->data[i]);
	}
	// DO NOT FIND SQUARE ROOT (we are working with int)
	// return the distance
	return dist;
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
	// check for malloc error
	ListNode * ln = malloc(sizeof(ListNode));
	if (ln == NULL)
	{
		fprintf(stderr, "List Node Allocation error\n");
		return NULL;
	}
	ln->treenode = malloc(sizeof(TreeNode));
	if (ln->treenode == NULL)
	{
		fprintf(stderr, "Tree Node Allocation error\n");
		return NULL;
	}
	// initialize dim
	ln->treenode->dimension = dim;
	// both left and right childern will be NULL
	ln->treenode->left = NULL;
	ln->treenode->right = NULL;
	// allocate memory for data
	ln->treenode->data = malloc(sizeof(int) * dim);
	int i;
	for(i = 0; i < dim; i++)
	{
		ln->treenode->data[i] = arr[i];
	}
	// return a ListNode
	ln->next = NULL;
	return ln;
}
#endif


#ifdef TEST_LINKEDLISTCREATE
void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr)
{
	// create temp node using CreateNode
	// read from file into an array, pass array to CreateNode
	int * arr = malloc(sizeof(int) * n * dim);
	int i;
	for (i = 0; i < n * dim; i++)
	{
		fscanf(fptr, "%d", &arr[i]);
	}
	// assign temp to that node
	ListNode * ln = CreateNode(n, dim, arr);
	ListNode * temp = ln;

	// use a loop to create nodes for the remaining elements of the list.
	for(i = dim; i < n * dim; i += dim)
	{
		ListNode * node = CreateNode(n, dim, &arr[i]);
		temp->next = node;
		temp = node;
	}
	*head = ln;
	free(arr);
}
#endif
