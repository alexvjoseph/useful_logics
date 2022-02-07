/* 

A C program to out-put a christmas tree pattern

####SAMPLE OUT PUT#######

repo$ ./tree
Enter the level
10
                                                               
                                  *                            
                               *  *  *                         
                            *  *  *  *  *                      
                         *  *  *  *  *  *  *                   
                      *  *  *  *  *  *  *  *  *                
                   *  *  *  *  *  *  *  *  *  *  *             
                *  *  *  *  *  *  *  *  *  *  *  *  *          
             *  *  *  *  *  *  *  *  *  *  *  *  *  *  *       
          *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *    
       *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * 
repo$ 


*/


#include <stdio.h>

int main(){
	int i, j, n, k;
	k = 0;
	printf("Enter the level\n");
	scanf("%d", &n);

	for(i=0; i<n+1; i++)
	{
		for(j=0; j<(n*2)+1; j++)
		{

			if(j>((n+1)-k) && j<((n+1)+k))
			{
				printf(" * ");
			}
			else
			{
				printf("   ");

		        }
		}

		k++;
		printf("\n");
	}
}
