/* A C program to demonstrate buffer overflow, 
and access violation, segmentation fault scenario


####SAMPLE OUT PUT#######

~/work/repo$ gcc -g test.c -o test 
~/work/repo$ ./test
Enter the string
werty
String recieved is werty 
~/work/repo$ ./test
Enter the string
wrtyuy
String recieved is wrtyuy 
~/work/repo$ ./test
Enter the string
wertyui
String recieved is wertyui 
*** stack smashing detected ***: <unknown> terminated
Aborted (core dumped)


*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	// Reserve 6 byte of buffer plus the terminating NULL.
	// should allocate 8 bytes = 2 double words,
	// To overflow, need more than 6 bytes...
	char buffer[6]; // If more than 6 characters input
						// by user, there will be access
						// violation, segmentation fault

	printf("Enter the string\n");

	//read until new line
	scanf("%[^\n]", buffer);

	printf("String recieved is %s \n", buffer);
	return 0;
}

