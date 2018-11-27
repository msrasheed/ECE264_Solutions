// You can modify this file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"

// DO NOT MODIFY THIS FUNCTION
void PrintAns(ListNode* head, ListNode* min1, ListNode* min2)
{
	int i;
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
MODIFY BELOW THIS COMMENT
*/


#ifdef TEST_CENT
ListNode* FindCentroid(TreeNode* x, TreeNode* y)
{
	// Create a new node
	// new -> treenode.left should be x
	// new -> treenode.right should be y
	// x -> treenode.data should be less than y -> treenode.data (refer to README)
	
	// Use a loop to average the data from the two parameters (x and y).
	/*
	EXAMPLE
	Average x->treenode.data[0] and y->treenode.data[0] to new->treenode.data[0]
	Average x->treenode.data[1] and y->treenode.data[1] to new->treenode.data[1]
	and so on
	*/
	int * arr = malloc(sizeof(int) * x->dimension);
	int i;
	for(i = 0; i < x->dimension; i++)
	{
		arr[i] = (x->data[i] + y->data[i]) / 2;
	}
	ListNode * ln = CreateNode(1, x->dimension, arr);
	free(arr);
	ln->treenode->left = x;
	ln->treenode->right = y;
	// Return the new node
	return ln;
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


#ifdef TEST_FUSE
ListNode* Fuse(ListNode* head, ListNode* fuse1, ListNode* fuse2)
{
	// Create a new ListNode element using findCentroid function.
	ListNode * ln = FindCentroid(fuse1->treenode, fuse2->treenode);
	// The new->treenode.data will hold the averaged values of the two parameters' data (fuse1, and fuse2)
	// add the new ListNode to the list.
	ln->next = head;
	// remove the fuse1 and fuse2 from the list. (Do NOT free)
	head = ln;
	ListNode * p = head;
	ListNode * n = p->next;
	while(n != NULL)
	{
		if(n == fuse1 || n == fuse2)
		{
			p->next = n->next;
		}
		else
		{
			p = p->next;
		}
		n = p->next;
	}
	// you may want to return head from this function (depending on your implementation)
	return head;
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

#ifdef TEST_CLUSTER
void MakeCluster(ListNode** head)
{
	// Walk through the linked list.
	// find pair of nodes with minimum distance.
	// fuse the two nodes into one node.
	// call print function
	// repeat till one node is remaining.
	ListNode * h = *head;
	while(h->next != NULL)
	{
		ListNode * sHead = h;
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
		while(i < h->treenode->dimension)
		{
			if(hold1->treenode->data[i] < hold2->treenode->data[i])
			{
				sHead = hold1;
				iter = hold2;
				i = h->treenode->dimension;
			}
			else if (hold1->treenode->data[i] > hold2->treenode->data[i])
			{
				sHead = hold2;
				iter = hold1;
				i = h->treenode->dimension;
			}
			i++;
		}
		h = Fuse(h, sHead, iter);
		PrintAns(h, sHead, iter);
		free(sHead);
		free(iter);
	}
	*head = h;
}
#endif


