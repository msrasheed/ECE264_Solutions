 # include <stdio.h>
 # include <stdlib.h>

 int main ( int argc , char * * argv )
 {
 // a two - dimensional array of integers
 // 5 rows and 3 columns
 int * * array2d ;
 array2d = malloc ( sizeof ( int * ) * 5);
 int row ;
 int col ;
 for ( row = 0; row < 5; row ++)
 {
 array2d [ row ] = malloc ( sizeof ( int ) * 3);
 }
 // assign zero to all elements
 for ( row = 0; row < 5; row ++)
 {
 for ( col = 0; col < 3; col ++)
 {
 array2d [ row ][ col ] = 0;
 }
 }

 // release memory
 for ( row = 0; row < 5; row ++)
 {
 free ( array2d [ row ]);
 }
 free ( array2d );
 return EXIT_SUCCESS ;
 }
