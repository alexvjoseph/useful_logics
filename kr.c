#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>


void print_bin(unsigned int byte);

unsigned kr(unsigned value, unsigned position, unsigned number);
int main(){

        
        unsigned int a, p, n, res;

	printf("Enter the number to be handled\n");
	scanf("%d", &a);

	printf("Enter the position of bit and number of bits\n");
	scanf("%d%d", &p, &n);

    res = kr(a, p, n);

    if(res != a)
    {
        
	printf("Result is \n");

	print_bin(res);
	printf("\n");
	return 0;
    }
    else
    {
    		printf("position and number of bits to be changed exceeded the limit of the size of the number\n");
    }
}

void print_bin(unsigned int byte)
{
    unsigned int i = 0, temp = 0;
    i = sizeof(i)*8; /* however many bits are in a int on your platform */
    temp = temp | 0x1 << (i-1) ;
    while(i--) {
       // printf("%x", (byte & temp ));
       // byte = byte << 1;
       putchar('0' + ((byte >> i) & 1)); /* loop through and print the bits */

    }
    printf("\n");
}


unsigned kr(unsigned value, unsigned position, unsigned number)
{
	
	unsigned int i = 0,  s = 0, left_val = 0, right_val = 0, orig = 0, temp = 0;
    s = sizeof(value);
	s = s*8; /*multiplied to get total number of bits */
	


	orig = value;
	i = number;
       
	//If the positions to be handled is inside the limit, proceed  
	if(s- (position + number) >= 0){
		
		//Value to be processed is shifted right up to the end of last bit to be reversed
		left_val =  value >> (s - position);
                left_val = left_val << (s - position);
               
		right_val = value << position+number ;
		right_val = right_val >> position+number;

		orig = orig >> (s - (position + number));
 
                temp =  temp | orig;

		temp = temp << (s - ((position + number)));

                temp = temp << (position);

		temp = temp >> position;

		temp = ~ temp;

		temp = temp >> (s - (position + number));
		temp = temp << (s - (position + number));

                temp = temp << (position);
		temp = temp >> position;


		printf("\nOriginal value is \n");
                print_bin(value);
	        return (temp | left_val | right_val);
	}

	else 
	{
          
          return value;

    }
}

