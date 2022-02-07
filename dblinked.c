/* 

	A C program to demonstrate doubly linkedlist

	Insert a value at last node
	print the values
	delete all nodes which holds a particular value
	delete a node at a position
	Add at a position

	

####SAMPLE OUT PUT#######

repo$ ./dblinked 
Enter the number of values to be added in the list
5

Enter the 1 th value to be added in the list
4


Previous adress: NULL Current adress:0x55d609046a80 Next adress: NULL Value: 4



Enter the 2 th value to be added in the list
5


Previous adress: NULL Current adress:0x55d609046a80 Next adress: 0x55d609046aa0 Value: 4
Previous adress: 0x55d609046a80 Current adress:0x55d609046aa0 Next adress: NULL Value: 5



Enter the 3 th value to be added in the list
6


Previous adress: NULL Current adress:0x55d609046a80 Next adress: 0x55d609046aa0 Value: 4
Previous adress: 0x55d609046a80 Current adress:0x55d609046aa0 Next adress: 0x55d609046ac0 Value: 5
Previous adress: 0x55d609046aa0 Current adress:0x55d609046ac0 Next adress: NULL Value: 6



Enter the 4 th value to be added in the list
7


Previous adress: NULL Current adress:0x55d609046a80 Next adress: 0x55d609046aa0 Value: 4
Previous adress: 0x55d609046a80 Current adress:0x55d609046aa0 Next adress: 0x55d609046ac0 Value: 5
Previous adress: 0x55d609046aa0 Current adress:0x55d609046ac0 Next adress: 0x55d609046ae0 Value: 6
Previous adress: 0x55d609046ac0 Current adress:0x55d609046ae0 Next adress: NULL Value: 7



Enter the 5 th value to be added in the list
8


Previous adress: NULL Current adress:0x55d609046a80 Next adress: 0x55d609046aa0 Value: 4
Previous adress: 0x55d609046a80 Current adress:0x55d609046aa0 Next adress: 0x55d609046ac0 Value: 5
Previous adress: 0x55d609046aa0 Current adress:0x55d609046ac0 Next adress: 0x55d609046ae0 Value: 6
Previous adress: 0x55d609046ac0 Current adress:0x55d609046ae0 Next adress: 0x55d609046b00 Value: 7
Previous adress: 0x55d609046ae0 Current adress:0x55d609046b00 Next adress: NULL Value: 8




Previous adress: NULL Current adress:0x55d609046a80 Next adress: 0x55d609046aa0 Value: 4
Previous adress: 0x55d609046a80 Current adress:0x55d609046aa0 Next adress: 0x55d609046ac0 Value: 5
Previous adress: 0x55d609046aa0 Current adress:0x55d609046ac0 Next adress: 0x55d609046ae0 Value: 6
Previous adress: 0x55d609046ac0 Current adress:0x55d609046ae0 Next adress: 0x55d609046b00 Value: 7
Previous adress: 0x55d609046ae0 Current adress:0x55d609046b00 Next adress: NULL Value: 8


Enter the value to be deleted from the list
6


Previous adress: NULL Current adress:0x55d609046a80 Next adress: 0x55d609046aa0 Value: 4
Previous adress: 0x55d609046a80 Current adress:0x55d609046aa0 Next adress: 0x55d609046ae0 Value: 5
Previous adress: 0x55d609046aa0 Current adress:0x55d609046ae0 Next adress: 0x55d609046b00 Value: 7
Previous adress: 0x55d609046ae0 Current adress:0x55d609046b00 Next adress: NULL Value: 8


Enter the value and position to be added to the list
9 5


Previous adress: NULL Current adress:0x55d609046a80 Next adress: 0x55d609046aa0 Value: 4
Previous adress: 0x55d609046a80 Current adress:0x55d609046aa0 Next adress: 0x55d609046ae0 Value: 5
Previous adress: 0x55d609046aa0 Current adress:0x55d609046ae0 Next adress: 0x55d609046b00 Value: 7
Previous adress: 0x55d609046ae0 Current adress:0x55d609046b00 Next adress: 0x55d609046ac0 Value: 8
Previous adress: 0x55d609046b00 Current adress:0x55d609046ac0 Next adress: NULL Value: 9


Enter the position to be deleted from the list
3


Previous adress: NULL Current adress:0x55d609046a80 Next adress: 0x55d609046aa0 Value: 4
Previous adress: 0x55d609046a80 Current adress:0x55d609046aa0 Next adress: 0x55d609046b00 Value: 5
Previous adress: 0x55d609046aa0 Current adress:0x55d609046b00 Next adress: 0x55d609046ac0 Value: 8
Previous adress: 0x55d609046b00 Current adress:0x55d609046ac0 Next adress: NULL Value: 9


*/


#include <stdio.h>
#include <stdlib.h>

struct node {

	struct node* prev;
	int val;
	struct node* next;

};

struct node* head;

void addList(int val){
	//creating new node
	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->next = NULL;
	temp->val = val;
	//if no elements are in the list add the new node as head
	if(head == NULL){
		temp->prev = NULL;
		head = temp;
		return;
	}

	struct node* last = head;
	//traverse through the list until the last node is found 
	//and the new node is added at the end 
	while(last != NULL){
		if(last->next == NULL)
		{
			last->next = temp;
			temp->prev = last;
			return;
		}
	 	last = last->next;
	}

}

void printList(){
	struct node* last = head;
	printf("\n\n");
	if(last == NULL)
	{
		printf("List is empty\n\n");
	}

	//traverse through the list
	while(last != NULL){
		if(last->prev!=NULL && last->next!=NULL){
			printf("Previous adress: %p Current adress:%p Next adress: %p Value: %d\n", last->prev, last, last->next, last->val);
		}
		else if(last->prev!=NULL)
		{
			printf("Previous adress: %p Current adress:%p Next adress: NULL Value: %d\n", last->prev, last, last->val);
		}
		else if(last->next!=NULL)
		{
			printf("Previous adress: NULL Current adress:%p Next adress: %p Value: %d\n", last, last->next, last->val);
		}
		else if(last->next==NULL && last->prev==NULL && last != NULL)
		{
			printf("Previous adress: NULL Current adress:%p Next adress: NULL Value: %d\n", last, last->val);
		}

		last = last->next;
	}

printf("\n\n");

}

//made a function that can be called recursively 
//until all the occurances of a particular value is removed from the list
int delVal(int val){

	struct node* temp = NULL;
	if(head == NULL){
		return 0;
	}
	temp = head;
//if the value is presented on 1st node
	if(temp->val == val){
		if(temp->next == NULL){
			free(temp);
			return 0;
		}
		temp->next->prev = NULL;
		head = temp->next;
		free(temp);
		return 1;
	}

//traversing through the list
	while(temp != NULL){
	if(temp->val == val)
		{
			//made memory corruption safe checks & assignments for a 1st or last node
			if(temp->next == NULL || temp->prev == NULL)
			{
				if(temp->next == NULL)
				{
				  temp->prev->next = NULL;
				}
				if(temp->prev == NULL)
				{
				  temp->next->prev = NULL;
				}
			}
			//value found in an in-between node
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			free(temp);
			return 1;
		}

	temp = temp->next;

	}

	return 0;
}

void addVal(int val, int n)
{
	int count = 1;
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	struct node* traverse = NULL;
	temp->val = val;
	//if list is empty and value is asked to add at first position
	if(head == NULL & n == 1){
		head = temp;
		temp->next = NULL;
		temp->prev = NULL;
		return;
	}
	count++;
	traverse = head;
	//traversing through the list until the position is reached
	while(traverse != NULL){
				if(count == n){
					temp->prev = traverse;
					//if the node is last node
					if(traverse->next == NULL){
						temp->next = NULL;
						}
					//node is an in-between node
					else{
						temp->next = traverse->next;
						}
					traverse->next = temp;
					return;
				}
			//next node is considered and count is increased
			traverse = traverse->next;
			count++;
		}
	return;
}

void delPos(int n)
{
        int count = 1;
        struct node* traverse = NULL;
        if(head == NULL){
                return;
        }

        traverse = head;
        while(traverse != NULL){
                                if(count == n){
                                        if(traverse->next != NULL)
						{      //if  node is first node with further nodes present
							if(traverse->prev == NULL){
								traverse->next->prev = NULL;
								head = traverse->next;
								free(traverse);
								return;
							}
						       //if node is an in between node
							traverse->next->prev = traverse->prev;
							traverse->prev->next = traverse->next;
							free(traverse);
							return;
						}
					//if node is  last node.
					if(traverse->prev == NULL){
					//if list has a single node **special case, then node is head
						free(head);
						head = NULL; // for avoid dangling
						return;
						}
					traverse->prev->next = NULL;
					free(traverse);
                                        return;
                                }
			//next node is considered and count is increased
                        traverse = traverse->next;
                        count++;
                }
        return;
}


int main(){


        int n, val;
        uint i;
        head = NULL;

        printf("Enter the number of values to be added in the list\n");
        scanf("%d", &n);

        for(i=0;i<n;i++){
                printf("\nEnter the %d th value to be added in the list\n", i+1);
                scanf("%d", &val);
                addList(val);
	        printList();
        }

	printList();
	printf("Enter the value to be deleted from the list\n");
	scanf("%d", &val);
	while(delVal(val) != 0){
	printList();
	}
	printf("Enter the value and position to be added to the list\n");
	scanf("%d %d", &val, &n);
	addVal(val, n);
	printList();

	printf("Enter the position to be deleted from the list\n");
	scanf("%d", &val);
	delPos(val);
        printList();

	return 0;

}


