#include <stdio.h>

#define MAX 10

int arr[ MAX ] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };//initialisation

int binarysearch( int begin, int end, int data )
{
	if( begin > end ) return -1;

	int mid = ( begin + end ) / 2;

	if( arr[ mid ] == data ) return mid;

	if( arr[ mid ] < data ) begin = mid + 1;
	else end = mid - 1;

	return binarysearch( begin, end, data );//return statement
}

int main()
{
	int begin = 0, end = MAX - 1, mid = ( begin + end ) / 2, data, pos;

	printf( "Enter what to search: " );
	scanf( "%d", &data );

	pos = binarysearch( begin, end, data );//function call

	if( pos == -1 ) 
		printf( "Element not found in the array.\n" );
	else 
		printf( "Element found in array at position %d.\n", pos + 1 );
	return 0;
}
