#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>

#define WORD_SIZE 8


void print_bin(unsigned int byte);

unsigned kr(unsigned value, unsigned position, unsigned number);
int main(){

        
       unsigned int a, p, n, res;

       printf("Enter the number to be handled\n");
       scanf("%d", &a);

       printf("Enter the position of bit and number of bits\n");
       scanf("%d%d", &p, &n);

       res = kr(a, p, n);

       //if return value is the same send value, it indicates the limits of operation exceeded, else print the new value 
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
		i = sizeof(i)*WORD_SIZE; /* however many bits are in a int on your platform */
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
	s = s*WORD_SIZE; /*multiplied to get total number of bits */
	


	orig = value;
	i = number;
       
	//If the positions to be handled is inside the limit, proceed  
	if(s- (position + number) >= 0){
		
			//Value is shifted right up to the begining of 1st bit to be reversed, 
			//for setting rest of bits on right to zero
			left_val =  value >> (s - position);
			
			//shifted back to retain the values on left side, having a zero right half
			left_val = left_val << (s - position);
			 
			//Value is shifted left up to the end of last bit to be reversed, 
			//for setting rest of bits on left to zero      
			right_val = value << position+number ;

			//shifted back to retain the values on right side, having a zero left half
			right_val = right_val >> position+number;

			//Mapping group of bit to be handled to a temporary variable
			orig = orig >> (s - (position + number));
			temp =  temp | orig;

			//setting all the bits to right of group of bits need to be changed to zero
			temp = temp << (s - ((position + number)));
			temp = temp << (position);
			temp = temp >> position;

			//complimenting the group of bits, however all rest of bits will set to 1 as they are zeros now
			temp = ~ temp;

			//steps again to clear left and right bits of the group of bits back to zero
			temp = temp >> (s - (position + number));
			temp = temp << (s - (position + number));
			temp = temp << (position);
			temp = temp >> position;


			printf("\nOriginal value is \n");
			print_bin(value);

			//bitwise OR to create the required result, left portion | middle portion | right portion
			return (temp | left_val | right_val);
	}

	else 
	{
          
          return value;

    }
}

