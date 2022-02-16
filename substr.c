/* 

A C program to find all strings holds a substring from a 2D array 

####SAMPLE OUT PUT #########

code_exercise$ ./substr 
Enter the paragraph: 
Here, are cons/drawback of semaphore
One of the biggest limitations of a semaphore is priority inversion.
The operating system has to keep track of all calls to wait and signal semaphore.
Their use is never enforced, but it is by convention only.
In order to avoid deadlocks in semaphore, the Wait and Signal operations require to be executed in the correct order.
Semaphore programming is a complex method, so there are chances of not achieving mutual exclusion.
It is also not a practical method for large scale use as their use leads to loss of modularity.
Semaphore is more prone to programmer error.
It may cause deadlock or violation of mutual exclusion due to programmer error.
Semaphore semaphore


Entered paragraph is: 

Here, are cons/drawback of semaphore
One of the biggest limitations of a semaphore is priority inversion.
The operating system has to keep track of all calls to wait and signal semaphore.
Their use is never enforced, but it is by convention only.
In order to avoid deadlocks in semaphore, the Wait and Signal operations require to be executed in the correct order.
Semaphore programming is a complex method, so there are chances of not achieving mutual exclusion.
It is also not a practical method for large scale use as their use leads to loss of modularity.
Semaphore is more prone to programmer error.
It may cause deadlock or violation of mutual exclusion due to programmer error.
Semaphore semaphore


Enter the substring to be detected: 
semaphore


Matched lines are:

Here, are cons/drawback of semaphore
One of the biggest limitations of a semaphore is priority inversion.
The operating system has to keep track of all calls to wait and signal semaphore.
In order to avoid deadlocks in semaphore, the Wait and Signal operations require to be executed in the correct order.
Semaphore semaphore


Number of occurences is 5

*/

#include <stdio.h>
#include <string.h>

#define STRING_SIZE 300
#define SUBSTRING_SIZE 8
#define LINE_NUMBER 10

int main()
{
	unsigned int i = 0, k = 0;
	char para[LINE_NUMBER][STRING_SIZE];
	char sbstr[SUBSTRING_SIZE];

	char result[LINE_NUMBER][STRING_SIZE];

	printf("Enter the paragraph: \n");

 
 	for(i=0; i<LINE_NUMBER; i++)
 		{
 				fgets(para[i], STRING_SIZE, stdin);
 		}

    printf("\n\nEntered paragraph is: \n\n");

    for(i=0; i<LINE_NUMBER; i++)
    	{
    			   printf("%s", para[i]);
    	}

    printf("\n\n");
 	printf("Enter the substring to be detected: \n");

    //bound read
 	fgets(sbstr, SUBSTRING_SIZE, stdin);


    printf("\n\nMatched lines are:\n\n");

 	for(i=0; i<LINE_NUMBER; i++)
 	{
 			   if(strstr(para[i],sbstr))
 			   {
 			   	    //bound copy
 			   		strncpy(result[k], para[i], STRING_SIZE);
 			   		printf("%s", result[k]);
 			   		k++;
 			   }
 	}

 	    printf("\n\nNumber of occurences is %d", k);
 	    printf("\n\n");

}