// ***
// *** You MUST modify this file
// ***

#include "josephus.h"
#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_JOSEPHUS
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails,
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  int i;
  for (i = 0; i < n; i++) 
  {
	  arr[i] = 1;
  }
  int index = -1;
  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
  for (i = 0; i < n-1; i++)
  {
	  int j = 0;
	  while (j < k)
	  {
		  index++;	  
		  if (index >= n) index = 0;
		  if (arr[index] != 0)
		  {
			  j++;
		  }
	  }
	  arr[index] = 0;
	  printf("%d\n", index);
  }

  // print the last one
  index = 0;
  while (arr[index] == 0)
  {
	  index++;
  }
  printf("%d\n", index);



  // release the memory of the array
  free (arr);
}
#endif
