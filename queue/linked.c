/*
Joshua Köhler - 1/27/2020 - Implementation of a queue with a linked list
*/
#include<stdlib.h>
#include<stdio.h>
struct node{
	int data;
	struct node* next;
};
void init(struct node** headAddress,struct node** tailAddress);
int isEmpty(struct node** headAddress, struct node** tailAddress);
void enqueue(struct node** headAddress,struct node** tailAddress,int value);	
int isEmpty(struct node** headAddress, struct node** tailAddress);
int dequeue(struct node** headAddress,struct node** tailAddress);

/* Print all data in the queue
*/
void print(struct node** headAddress,struct node** tailAddress){
	struct node* temp = *headAddress; //local variable for traversal
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;//increment
	}
	printf("\n");
}

/*
pass a pointer to the head (which points at the first element)
In other words, pass a pointer to a pointer to the first element
Ditto for the tail.
We want the pointer to the first element(head), and the pointer to the last 
element (tail) to be set to NULL when the queue is empty.

*headAddress is the same thing as head
*tailAddress is the same thing as tail
*/
void init(struct node** headAddress,struct node** tailAddress){
*headAddress=*tailAddress=NULL;//nothing in the list
}

/*enqueue(struct node** headAddress, struct node** tailAddress, int value)
Adds value at position at tail
If the list is empty, 
head points at the same thing tail points at (first element).

If the list is not empty,
have the previous last element point at the added element
have tail point at the new last element

*headAddress is the same thing as head
*tailAddress is the same thing as tail
*/
void enqueue(struct node** headAddress,struct node** tailAddress,int value){	
	//These three lines create and set-up the new node
	struct node* add = malloc(sizeof(struct node));//create new node
	add->data=value;//set its data value
	add->next=NULL;//we are adding to the end of the list, so next=NULL
	
	if(add==NULL){//malloc failed - heap full etc.
		printf("Malloc Failed!\n");
		return;
	}
	
	else if(isEmpty(headAddress, tailAddress)){//list empty
		*tailAddress=add;//have tail point to add --- tail=add
		*headAddress=*tailAddress;//head and tail point to the same element to start
	}
	else{//list is not empty
		(*tailAddress)->next=add; //extend the list
		*tailAddress=add;//have tail point to the extension
	}
}

/*
Returns 1 if list is empty
Returns 0 if list is not empty
The list is empty if tail and head are NULL
*/
int isEmpty(struct node** headAddress, struct node** tailAddress){
	if(*headAddress==NULL && *tailAddress==NULL) {//the list is empty
		return 1;
	}
	else{//list not empty
		return 0;
	}
}

/*
Removes front (oldest) element
Returns the data value from this element
Head now will point at the 2nd oldest element

*headAddress is the same thing as head
*tailAddress is the same thing as tail
*/
int dequeue(struct node** headAddress,struct node** tailAddress){
	if(isEmpty(headAddress,tailAddress)){//list is empty
		printf("Cannot dequeue - list is empty!\n");
		return -1;
	}
	else if((*headAddress)->next==NULL){//there is only one value in the list
		int ret = (*headAddress)->data;//save data value to return in ret
		printf("Last dequeue!\n");
		free(*headAddress);//free the element whose address is stored in head/tail
		*headAddress=*tailAddress=NULL;//set head and tail to NULL (list is empty)
		return ret;//return data value of dequeued node
	}
	else{//list has at least two elements
		int ret = (*headAddress)->data;//save data value to return in ret
		printf("Normal mode\n");
		struct node* destroy = *headAddress;//save node to destroy
		*headAddress=(*headAddress)->next;
		return ret;//return data value of dequeued node
	}
}

/* 
Test my linked list implementation of a queue.
*/
void main(void){//let's test our functions now
	struct node* head, *tail; //declare head and tail pointers
	init(&head,&tail);
	enqueue(&head,&tail,5);//add 5 to queue
	print(&head,&tail);
	enqueue(&head,&tail,7);//add 7 to queue
	print(&head,&tail);
	printf("Dequeue = %d\n",dequeue(&head,&tail));
	print(&head,&tail);
	printf("Dequeue = %d\n",dequeue(&head,&tail));
	print(&head,&tail);
	printf("Dequeue = %d\n",dequeue(&head,&tail));
	print(&head,&tail);
	printf("Dequeue = %d\n",dequeue(&head,&tail));
}




	
