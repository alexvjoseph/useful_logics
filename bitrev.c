/* 

A C program to reverse bits of a byte

####SAMPLE OUT PUT#######

repo$ ./bitrev
Enter the number to be reversed
235
Binary representation of the number enetered is:
11101011
Hex representation of the value is eb: and size is 1
Number enetered originally is:
11101011
Number reversed is:
11010111



*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>


void print_bin(unsigned char byte);


int main(){

        uint8_t a, s, i, rev, orig;
	i = 1;
	rev = 0;
	printf("Enter the number to be reversed\n");
	scanf("%d", &a);

	orig = a;

	printf("Binary representation of the number enetered is:\n"); 
	print_bin(orig);
	printf("\n");
	
	s = sizeof(a);

	printf("Hex representation of the value is %x: and size is %d\n", a, s);

	while(i < 8){
		rev = rev<<1;
		rev = rev | a & 0x1;
		a = a>>1;
		i++;
	}
	printf("Number enetered originally is:\n"); 
	print_bin(orig);
	printf("\n");
        printf("Number reversed is:\n"); 
	print_bin(rev);
	printf("\n");
	return 0;
}

void print_bin(unsigned char byte)
{
    int i = CHAR_BIT; /* however many bits are in a byte on your platform */
    while(i--) {
        putchar('0' + ((byte >> i) & 1)); /* loop through and print the bits */
    }
}

