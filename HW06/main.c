// ***
// *** Please modify this file, as indicated
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "vector.h"

/*-------------------------------MODIFY BELOW THIS LINE-------------------------------*/

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
    // input file will be specified from the terminal - test files are made available in inputs folder

    // check for missing input file/output file, if so, "return EXIT_FAILURE;"
    if (argc < 3) 
    {
	    fprintf(stderr, "Need 2 arguments, only have %d\n", argc);
	    return EXIT_FAILURE;
    }
    // store the input file name in a variable, from argv[1]. For example, char* in_file = argv[1];
    // store the output file name in a variable, from argv[2]. For example, char* out_file = argv[2];
    char* inputFile = argv[1];
    char* outputFile = argv[2];
    FILE * testOpen = fopen(inputFile, "rb");
    if(testOpen == NULL)
    {
	    fprintf(stderr, "Input file open fail");
	    return EXIT_FAILURE;
    }
    fclose(testOpen);
    testOpen = fopen(outputFile, "wb");
    if(testOpen == NULL)
    {
	    fprintf(stderr, "Output file open fail");
	    return EXIT_FAILURE;
    }
    fclose(testOpen);
    // call numberOfElements(in_file) to obtain the number of elements in the file.
    int numElems = numberOfElements(inputFile);
    // allocate memory to store the numbers (initialize an array of structures)
    Vector* vectors = malloc(sizeof(Vector) * numElems);
            // check for malloc fail, if so, "return EXIT_FAILURE;"
    if(vectors == NULL)
    {
	    fprintf(stderr, "malloc fail\n");
	    return EXIT_FAILURE;
    }
    //call the fillVector(vector, count, in_file); and store the values from the file in the array of strucures.
    fillVector(vectors, numElems, inputFile);

    //Use qsort() function, after defining the comparator() function.
            //ENSURE THE COMPARATOR FUNCTION IS USED TO SORT THE ARRAY OF STRUCTURES W.R.T. THE STRUCTURE VARIABLE "x".
    vectorsCheck(vectors, numElems);
    qsort(vectors, numElems, sizeof(Vector), cmp);

    //call the writeFile(vector,count, out_file); to save the sorted vector into the file.
    vectorsCheck(vectors, numElems);
    writeFile(vectors, numElems, outputFile);
    free(vectors);
    return EXIT_SUCCESS;
}
#endif
