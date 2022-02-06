/* 
	Insert a value at last node
	print the values
	delete all nodes which holds a particular value
	delete a node at a position
	Add at a position
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{

        int val;
        struct node *next;

};

struct node* head;

void insertLast(int x){

	struct node * temp = (struct node *) malloc(sizeof(struct node));

	temp->val  = x;
	temp->next = NULL;

	if(head == NULL){
		head = temp;
		return;
	} else {
                struct node *Lastnode = head;
		while(Lastnode->next != NULL)
		{
			Lastnode = Lastnode->next;

                }

                Lastnode->next = temp; 
	}


}

void printList(){
	struct node * temp;
	temp = head;
	if(head == NULL){
		printf("\n\nLinked list is empty\n\n");
}

	while(temp != NULL){
		printf("Adress of the node is: %p and Value of the node is: %d\n", temp, temp->val);
		temp = temp->next;
	}


}

int deleteVal(int val){
	struct node* temp = head;
	struct node* prev = NULL;

	if(temp != NULL && temp->val == val){
		head = temp->next;
		free(temp);
	}
	if(head == NULL){
		return 0;
	}
	prev = head;
	temp = head->next;
	while(temp!=NULL){
		if(temp->val==val){
					prev->next = temp->next;
					free(temp);
					return 1;
				}
		prev = temp;
		temp = temp->next;
	}

	return 0;

}

void deletePosition(int n){

	struct node* temp = NULL;
	struct node* prev = head;

	unsigned int count = 0;

	if(head == NULL){

		return;

	}
	count++;
	temp = head->next;
	while( temp != NULL){

			if(count+1 == n){

					prev->next = temp->next;
					free(temp);
					return;

				}

			count++;
			prev = temp;
			temp = temp->next;

			}

	return;

}

void addPosition(int n, int val){
	int count = 0;
	struct node* travNode = NULL;
	struct node* saveNode = NULL;
	struct node* temp = (struct node *) malloc(sizeof(struct node));
	temp->val  = val;
	temp->next = NULL;

	if(head == NULL){
		head = temp;
		return;
	}
	count++;
	travNode = head;
	while(travNode != NULL){
		if(count+1 == n){

			saveNode = travNode->next;
			travNode->next = temp;
			temp->next     = saveNode;
			return;

		}
		travNode = travNode->next;
		count++;
	}
	return;
}

int main()
{
	int n, val;
	uint i;
        head = NULL;

	printf("Enter the number of values to be added in the list\n");
        scanf("%d", &n);


	for(i=0;i<n;i++){
		printf("\nEnter the %d th value to be added in the list\n", i+1);
//		scanf("%d", &val);
		insertLast(i);
		printList();
	}

//	printf("Enter the value to be deleted from the list\n");
//	scanf("%d", &val);
//	while(deleteVal(val) != 0);
//	printList();
//	printf("Enter the position to be deleted from the list\n");
//	scanf("%d", &val);
//	deletePosition(val);
//	printList();
	printf("Enter the value and position to be added to the list\n");
	scanf("%d %d", &val, &n);

 	addPosition(n, val);
	printList();

	return 0;


}




