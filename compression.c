/*
##########################################################################################################################################
#    Data Compression Design
#    Design an algorithm that will compress a given data buffer of bytes. 
#
#    The algorithm will live within a function.  
#    This function will be called with two arguments; a pointer to the data buffer (data_ptr) and the number of bytes to compress (data_size). 
#    After the function executes the data in the buffer will be modified and the size of the modified buffer will be returned.
#
#    Assumptions:
#    1.	The data_ptr will point to an array of bytes.  Each byte will contain a number from 0 to 127 (0x00 to 0x7F). 
#     It is common for the data in the buffer to have the same value repeated in the series.
#    2.	The compressed data will need to be decompressable.
#     Please ensure that your algorithm allows for a decompression algorithm to return the buffer to it’s previous form.
#    
#    Example data and function call:
#    // Data before the call
#    // data_ptr[] = { 0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64, 
#    //                0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
#    //                0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09 };
#    // data_size = 24;
#    
#    new_size = byte_compress( data_ptr, data_size );
#    
#    
#############################################################################################################################################

#############################################################################################################################################
#SAMPLE OUTPUT:
#  $./compr 
#
#   Original data is printed below, it's size is: 782
#   3, 74, 4, 4, 4, 35, 35, 64, 64, 64, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
#   0, 0, 56, 45, 56, 56, 56, 56, 56, 56, 56, 56, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
#   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
#   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 45, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
#   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
#   0, 0, 0, 0, 0, 0, 0, 56, 45, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 9, 7, 1, 9, 9, 1, 2, 3, 
#   
#   Compressed size is 40
#   Original size is 782
#   
#   Compressed data is printed below
#   131, 202, 4, 2, 35, 1, 64, 3, 0, 99, 184, 173, 56, 8, 0, 80, 184, 173, 56, 8, 0, 80, 184, 173, 56, 126, 56, 126, 56, 126, 56, 95, 137, 135, 129, 9, 1, 129, 130, 131, 
#   
#   
#   decompressed data_size is: 782
#   
#   3, 74, 4, 4, 4, 35, 35, 64, 64, 64, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
#   0, 0, 56, 45, 56, 56, 56, 56, 56, 56, 56, 56, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
#   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
#   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 45, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#   0, 0, 0, 0, 0, 0, 0, 56, 45, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
#   56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 9, 7, 1, 9, 9, 1, 2, 3, 
#
#
##############################################################################################################################################


 */


#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

int byte_compress (unsigned char *data, unsigned int data_size);

int byte_decompress (unsigned char *data, unsigned int data_size);

void print_hex(unsigned char byte);

int main(){

   unsigned int data_size = 24;
   unsigned int compressed_size = 0;
   unsigned int decompressed_size = 0;
   unsigned int i = 0;


   unsigned char data[] = 
   { 
     3, 74, 4, 4, 4, 35, 35, 64, 64, 64, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 45, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 45, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 45, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56,
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 
     56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 9, 7, 1, 9, 9, 1, 2, 3
   };

	printf("\nOriginal data is printed below, it's size is: %ld\n", sizeof(data));
	for(i=0; i<sizeof(data); i++)
	    {
	    	print_hex(data[i]);
	    }

    compressed_size = byte_compress(data, sizeof(data));


	printf("\nCompressed size is %d\n", compressed_size);
	printf("Original size is %ld\n", sizeof(data));

	printf("\nCompressed data is printed below\n");
    for(i=0; i<compressed_size; i++)
	{
		print_hex(data[i]);
	}

    decompressed_size = byte_decompress(data, compressed_size);

//  printf("\n\nDecompressed data is \n\n");
//  for(i=0; i<decompressed_size; i++)
//  {
//  	print_hex(data[i]);
//  }


	printf("\n\n\n\n");

	return 0;

}

int byte_compress (unsigned char *data, unsigned int data_size)
{
	unsigned char * temp = NULL;
	unsigned int i = 0, j = 0;
	unsigned char count = 0, total_count = 0, equal_flag = 0;
    
 //   printf("Original data is below, it's size is %d\n\n", data_size);
 //	for(i=0; i<data_size; i++)
 //   {
 //   	print_hex(data[i]);
 //   }

    printf("\n");

 	temp = (unsigned char *)malloc(data_size*sizeof(unsigned char));
	if (temp == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else 
    {

         	for(i=0; i<data_size; i++)
         	{
         		//current and previous data are same
         		if (data[i+1] == data[i])
         		{
         			//counting number of the repeat
         			count = count + 1;
         			equal_flag =  1;
         			
         			//if count reached the maximum repeat count, place the data and restart the count
         			if (count == 0x7F)
         			{
         				temp[j] = data[i];
         				j++;

         				//special case for value repeating more than 127 times, one is substracted to avoid a single extra addition 
         				//when control hit each time at this point
         				temp[j] = count-1;
         				j++;

         				total_count = total_count + 2;

         				count = 0;
         				equal_flag =  0;
         			}
         			
         		}
         		else
         		{
         			//checking the previous value was a repeating one, if repeating save the value and count on adjecent position
         			if(equal_flag == 1)
         			{
         				
         				temp[j] = data[i];
         				j++;

         				temp[j] = count;
         				j++;

         				total_count = total_count + 2;

         				count = 0;
         				equal_flag =  0;
         			}
         			//non repeating value, set the MSB bit to tag this is a unique value compared to adjacent values
         			else
         			{
         				temp[j] = 0x80 | data[i];
         				j++;

         				total_count = total_count + 1;         				
         			}
         			
         		}
         
         	}
	}


 //   printf("\n\ni is: %d, data_size is: %d\n", i, data_size);
	for(i=0; i<total_count; i++)
    {
    	data[i] = temp[i];
    }

    free(temp);
    temp = NULL;

    return total_count;
	
}

int byte_decompress (unsigned char *data, unsigned int data_size)
{
	unsigned char * temp = NULL;
	unsigned int i = 0, j = 0, k = 0;
	unsigned char count = 0, total_count = 0, equal_flag = 0;
    
//    printf("\nCompressed data is below, it's size is %d\n\n", data_size);
//	  for(i=0; i<data_size; i++)
//    {
//    	print_hex(data[i]);
//    }

    printf("\n");

 	temp = (unsigned char *)malloc(data_size*sizeof(unsigned char));
	if (temp == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else 
    {

    	//Saving compressed array to a temporary variable for reference
        for(i=0; i<data_size; i++)
        {
        	temp[i] = data [i];
        }

        for(i=0; i<data_size; i++)
        {
        	//Checking whether the MSB is not set, if not set this is a repeating value
        	if(!(temp[i] & 0x80))
        	{
        		data[j] = temp[i];
        		for(k=0; k<temp[i+1]+1; k++)
        		{
        			data[j+k] = temp[i];
        		}

        		//Repeating data is filled, index moved to end of repeating data
        		j = j + k;

        		//k is reset
        		k = 0;

        		//next position is skipped, it was the repeat count which is handled above
        		i++;

        	}
        	else
        	{
        		//recreate the original value by reseting the MSB to zero
        		data[j] = temp[i] & 0x7f;
        		j++;
        	}
        }
            

	}


    printf("\n\ndecompressed data_size is: %d\n\n", j);
	for(i=0; i<j; i++)
    {
    	print_hex(data[i]);
    }

    free(temp);
    temp = NULL;

    return j;
	
}



void print_hex(unsigned char byte)
{
    printf("%d, ", byte);

   //printing in binary for debugging

 //  printf("\n");
 //  int i = CHAR_BIT; /* however many bits are in a byte on your platform */
 //  while(i--) {
 //      putchar('0' + ((byte >> i) & 1)); /* loop through and print the bits */
 //  }

}