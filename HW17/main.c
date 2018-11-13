#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

//***** YOU NEED TO MODIFY main() FUNCTION BELOW *******//
#ifdef TEST_MAIN
void FreeBinaryTree(treeNode * root);

int main(int argc, char **argv)
{

	/*
	 *  1. Check for number of arguments. If less than 2, do not proceed further.
	 */
	if (argc < 2) 
	{
		fprintf(stderr, "Not enough input arguments\n");
		return EXIT_FAILURE;
	}
	 /*  2. The program should create a binary search tree from the numbers in input file. The input file 
	 *  	also contains a number for search query at the end. 
	 *
	 *  3. The input file has one number per line. If there are 'n' lines in the file, the first n-1 numbers 
	 *  	are the elements of the binary search tree and the nth line is the search query. 
	 *  	NOTE: n is not given to you. 
	 *
	 *  4. Create an array of the first n-1 numbers and store the last number in a variable.
	 */
	FILE * fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Failed to open input file\n");
		return EXIT_FAILURE;
	}
	int i;
	int count = 0;
	while (fscanf(fptr, "%d", &i) == 1)
	{
		count++;
	}
	int * arr = malloc(sizeof(int) * (count - 1));
	if (arr == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for array\n");
		return EXIT_FAILURE;
	}
	fseek(fptr, 0, SEEK_SET);
	for (i = 0; i < count - 1; i++)
	{
		fscanf(fptr, "%d", &arr[i]);
	}
	int search;
	fscanf(fptr, "%d", &search);
	fclose(fptr);
	 /*  5. Create a Binary Search Tree. It takes four arguments:
	 *  	1. The array
	 *  	2. the first element of the array
	 *  	3. start index (index of first element of the array)
	 *  	4. end index ( index of last element of the array)
	 */
	treeNode * tree = CreateBST(arr, arr[0], 0, count-2);
	 /*  6. Print the created tree in Inorder fashion. Quick check if you have created the tree right: the output of
	 *  	will be a sorted array of numbers. 
	 */
	BinaryTreeInOrderPrint(tree);
	 /*  7. Compute the distance of the 'search query' node by passing it to the function.
	 */
	int dist = FindDistance(tree, search, 0);
	 /*  8. Use PrintDistance() function to print the distance of the node from the root node in the right format.
	 */
	PrintDistance(dist);
	 /*  9. Free all memory.
	 *
	 */
	free(arr);
	FreeBinaryTree(tree);
}

void FreeBinaryTree(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    FreeBinaryTree(root->leftChild);
    FreeBinaryTree(root->rightChild);
    free(root);
}
#endif
