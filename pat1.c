#include <stdio.h>

int  main(){

	unsigned int i, j, k, n;
	k = 0;
	printf("Enter the edge of the square\n");
	scanf("%d", &n);
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

