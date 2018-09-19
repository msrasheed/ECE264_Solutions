//
// MODIFY THIS FILE AS DIRECTED
//
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "vector.h"



#ifdef TEST_COMP
int cmp(const void *a, const void *b) 
{ 
    //typecast the inputs into Vector * form.
        //For example: Vector *typecasted_b = (Vector *)b;
    Vector * typecasted_a = (Vector *) a;
    Vector * typecasted_b = (Vector *) b;
    //compare typecased_a->x and typecasted_b->x, and return appropriate values.
    if(typecasted_a->x > typecasted_b->x) {return 1;}
    else if(typecasted_a->x < typecasted_b->x) {return -1;}
    else {return 0;}
} 
#endif

#ifdef TEST_COUNT
int numberOfElements(char* in_file_name)
{
    //initialize file_pointer, and open file in read mode. 
        //Please note that we are working with binary files. 
    FILE * fd = fopen(in_file_name, "rb");
    
    //use fseek(file_pointer, 0, SEEK_END); to point to the end of the file.
    fseek(fd, 0, SEEK_END);
    //use long where = ftell(file_pointer); to get the size of the file.
    long where = ftell(fd);
    //use float numelem = where / sizeof(Vector); to obtain the number of elements
    float numelem = where / sizeof(Vector);
    //return numelem; to send the number of elements back to main().
    fclose(fd);
    return numelem;
}
#endif

#ifdef TEST_FILL
void fillVector(Vector* vector, int count, char * in_file_name)
{
    // open binary file to read after initializing file_pointer 
    FILE * fd = fopen(in_file_name, "rb"); 
    //How to read the file?
        //use fread(vector, sizeof(Vector), count, file_pointer)
    fread(vector, sizeof(Vector), count, fd);
    fclose(fd);
}
#endif

#ifdef TEST_WRITE
void writeFile(Vector* vector, int count, char* out_file_name)
{
    // open binary file to write after initializing file_pointer
    FILE * fd = fopen(out_file_name, "wb");
    //How to write to the file?
        //use fwrite(vector, sizeof(Vector), count, file_pointer)
    fwrite(vector, sizeof(Vector), count, fd);
    fclose(fd);
}
#endif

void vectorsCheck(Vector * vector, int count)
{
	int i;
	for(i = 0; i < count - 1; i++)
	{
		if(vector[i].x > vector[i + 1].x)
		{
			printf("Not in order\n");
		}
	}
	printf("Ordered correctly\n");
}
