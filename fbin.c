/*A C program to printout Fibinocci number to a maximum range 

####SAMPLE RESULT#######
code_exercise$ ./fbin
Enter the maximum limit
10000

Fibonacci Series: 0, 1, 2, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765


*/


#include <stdio.h>

int  main(){

	unsigned int i = 0, next = 1, sum, prev = 1, n;

	printf("Enter the maximum limit\n");
	scanf("%d", &n);

	printf("\nFibonacci Series: %d, %d, ", i, next);

	sum = prev + next;

	while(sum < n)
	{
		//for clean print out
		if((prev + next) > n){

			printf("%d\n\n", sum);

		}

		else
		{

			printf("%d, ", sum);

		}


	     sum = prev + next;

		prev = next;
		next = sum;

	}

	return 0;

}
