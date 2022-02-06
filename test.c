// A C program to demonstrate buffer overflow
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
	scanf("%[^\n]", buffer);

	printf("String recieved is %s \n", buffer);
	return 0;
}

