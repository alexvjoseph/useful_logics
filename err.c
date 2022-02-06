#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>


void print_bin(unsigned char byte);

int ch(char c);

int ch(char c)
{
        int i;
       	static int k;
	for(i=0; i < (sizeof(c)*8); i++)
	{
		k =  k + (c >> i & 0x01); 
	}
	return k;

}


int main(){
        
	char abc = '8';
	int res;
	print_bin(abc);
	res = ch(abc);
	printf("result is %d\n", res);

	abc = 0xFF;

        print_bin(abc);
        res = ch(abc);
        printf("result is %d\n", res);
	
        abc = 0x0F;

        print_bin(abc);
        res = ch(abc);
        printf("result is %d\n", res);


}

void print_bin(unsigned char byte)
{
    int i = CHAR_BIT; /* however many bits are in a byte on your platform */
    while(i--) {
        putchar('0' + ((byte >> i) & 1)); /* loop through and print the bits */
    }
    printf("\n");
}


