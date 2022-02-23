/* 

A C program to out-put a daimond pattern

####SAMPLE OUT PUT#######

repo$ ./pat1 
Enter the edge of the square
5
    *    
   * *   
  *   *  
 *     * 
*       *
 *     * 
  *   *  
   * *   
    *    


*/


#include <stdio.h>

int  main(){

	unsigned int i, j, k, n;
	k = 0;
	printf("Enter the edge of the square\n");
	scanf("%d", &n);

	// 2*n is needed for creating the image
	// i variable is used to traverse vertically
	// j variable to traverse horizontally
	// k variable for inward/outward movement, if k less than n, start printing outward
	// if k greater than n, start printing inward
	// condition: j stretch from 0 to 2n, at each full for loop for j(ie horizontal traverse), maximum 2 times stars 
	// are printed symmetrically either side of middle position
	// k will move one position at each i step


	for(i=0;i<n*2-1;i++)
	{
		for(j=0;j<n*2-1;j++)
		{
					if((j+1 == n+k || j+1 == n-k))
					{
						printf("*");
					}
					else
					{
						printf(" ");
					}
		}

               if(i+1<n){
                         k++;
                      }
                   else{
                         k--;
                      }

		printf("\n");
	}


}

