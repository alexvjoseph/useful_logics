/* 

A C program to out-put a square

####SAMPLE OUT PUT#######

./pat2
Enter the edge size
7
* * * * * * * 
*           * 
*           * 
*           * 
*           * 
*           * 
* * * * * * * 


*/


#include <stdio.h>

int main(){

	unsigned int i, j, n;
	printf("Enter the edge size\n");
	scanf("%d", &n);


	for(i=0; i<n; i++){
		for(j=0;j<n;j++){

			if(i==0 || j == 0 || i == (n-1) || j == (n-1))
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}

}
