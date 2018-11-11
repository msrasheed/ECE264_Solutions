#include <stdio.h>
#include <stdlib.h>

int f2(int n, int m)
{
	if ((n <= 0) || (m <= 0))
	{
		return 0;
	}
	int a = f2(n--, m - 1);
	int b = f2(n--, m - 1);
	return (a + b + n);
}

int main(int argc, char ** argv)
{
	printf("f2(5,10) = %d\n", f2(5,10));
	return EXIT_SUCCESS;
}