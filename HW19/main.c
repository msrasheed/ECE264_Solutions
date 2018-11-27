// Please modify this file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw19.h"


#ifdef TEST_MAIN
void FreeBinaryTree(TreeNode *root);

int main(int argc, char * * argv)
{
	// check for input error
	if (argc < 2) 
	{
		fprintf(stderr, "Not enough input arguments\n");
		return EXIT_FAILURE;
	}
	// open the file
	FILE * fptr = fopen(argv[1], "r");
	// n is availavle in argv[1]
	int n;
	fscanf(fptr, "%d", &n);
	// dim is available in argv[2]
	int dim;
	fscanf(fptr, "%d", &dim);
	// input file is in argv[3]
	
	// Create linkedList
	ListNode * head;
	LinkedListCreate(&head, n, dim, fptr);
	fclose(fptr);
	// call MakeCluster
	MakeCluster(&head);

	FreeBinaryTree(head->treenode);
	free(head);

	return EXIT_SUCCESS;
}

void FreeBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    FreeBinaryTree(root->left);
    FreeBinaryTree(root->right);
    free(root->data);
    free(root);
}
#endif
