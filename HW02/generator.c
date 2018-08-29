
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char * * argv) 
{
	int size = atoi(argv[1]);
	int min = atoi(argv[2]);
	int max = atoi(argv[3]);

	srand(time(NULL));
	int i = 0;
	//int* arr[size];
	for (i = 0; i < size; i++)
	{
		//arr[i] = (int) (rand() * (max - min) + min);
		printf("%d\n", (int) (rand() * (max-min) + min));
	}
	return EXIT_SUCCESS;
}
