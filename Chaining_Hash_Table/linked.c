// Joshua Koehler - Linked List Implementation - 2/6/2020
// linked.c
/*
Contains the following functions:
listInit
listSize
listIsEmpty
listFrontAdd
listNodeDelete
printList
*/
#include "hash.h"

// allocate memory for a head node, and return the address of this node
struct node* listInit(void){
	struct node* head = NULL;// This is just a pointer, so don't malloc as that
													 // would produce a memory lead when listFrontAdd is 
													 // called. 
	return head;
}

/*listFind
if found: load in the matching first and last names, and return TRUE (1)
if NOT found: return FALSE (0)
*/
int listFind(struct node* sent,char* plate,char* first, char* last){
	while(sent!=NULL){
		if(!strcmp(sent->plate,plate)){//we found a match
			//load in the names
			strcpy(first,sent->first);
			strcpy(last,sent->last);
			return TRUE;//found
		}
		sent=sent->next;//increment
	}
	return FALSE;
}
	

//returns amount of nodes in the list
int listLen(struct node* head){
	int count=0;
	// traverse the list until a node has the address of null, if this is the case
	// then it is not a node, so don't count it
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
}

//return 1 (defined as TRUE) if list is empty 
//return 0 (defined as FALSE) if list has at least one real node
int listIsEmpty(struct node* head){
	if(head==NULL) return TRUE;
	else return FALSE;
}

//add newNode to front of list
struct node* listFrontAdd(struct node* head, struct node* newNode){
	struct node* temp;
	temp=head;//temp = where head WAS pointing
	head=newNode;//head now points to the (newNode)
	newNode->next=temp;//the added node now points to the previous first node
	return head;//return the address of the head node
}

// listNodeDelete deletes a node (whose address is passed) from a list (whose 
//address is passed.
int listNodeDelete(struct node* delete, struct node** head){
	struct node* temp; //for use in delete
	//if the node to delete is the first node
	if((*head)==delete){
		struct node* destroy=(*head);//save memory address so we can free it
		(*head)=(*head)->next;//skip first element
		free(destroy);
		return SUCCESS;//SUCCESS IS DEFINED AS 1
	}

	//if we got here, then the first node in the list is NOT the one to be deleted
	struct node* prev,*next; //keeps track of previous node, and use for traverse
	temp=(*head);
	while(temp!=NULL){//traverse list till end 
		//we don't need to have the if(temp==delete) first, because we know the 
		// first node isn't the one to be delted (SEE ABOVE)	
		prev=temp;
		temp=temp->next;	
		if(temp==delete){//if temp is the node to be deleted
			prev->next=temp->next; //skip temp
			free(temp); //delete the node	
		}
	}
	//if we got this far, then the node is not in the list
	return FAILURE; 
}
	
				
/*
This following functions are useful for PA3 (HASHMAP), but shouldn't be used in 
the linked list implementation
*/

//print every node in the list
void listPrint(struct node* head){
	while(head!=NULL){//till end of list
		printf("%s --- %s, %s\n",head->plate,head->first,head->last);
		head=head->next;//increment list
	}
}

/*having created a node, add the node to the hash table
void hashAdd(struct node** hashTable,char* plate,char* first,char* last){
	unsigned int index = hash(plate);//gets hash of plate
	struct node* newNode = createNode(plate,first,last);//allocates and fills node
	hashTable[index]=listFrontAdd(hashTable[index],newNode);//add node to chain 
}
*/	
//given field data, create new node and return its address
struct node* createNode(char* plate, char* first, char* last){
	//get lengths of all strings (for use in strcpying into our new node later)
	long int plateLen, firstLen, lastLen;
	plateLen=strlen(plate);
	firstLen=strlen(first);
	lastLen=strlen(last);
	
	//allocate memory for node to be added and give add its address
	struct node* add = malloc(sizeof(struct node));
	
	//Check for malloc fail - heap full
	if(add==NULL){
		printf("malloc of node failed!\n");
		exit(-1);
	}

	//allocate memory for strings
	add->plate = malloc(sizeof(char)*(plateLen+1));
	add->first = malloc(sizeof(char)*(firstLen+1));
	add->last = malloc(sizeof(char)*(lastLen+1));
	strcpy(add->plate,plate);
	strcpy(add->first,first);
	strcpy(add->last,last);
	add->next=NULL;//initialze this to NULL to make explicit
	return add;//return created node
}
	
//free all the nodes and their malloced parts in the linked list for PA3
struct node* listFree(struct node* head){
	struct node* prev;
	while(head!=NULL){
		prev=head; //save the bridge
		head=head->next;//cross the bridge
		//free bridges within the bridge
		free(prev->plate);
		free(prev->first);
		free(prev->last);
		free(prev);//burn the big bridge
	}
}
