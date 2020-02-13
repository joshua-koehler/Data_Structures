/*
This file contains all my hash functions for PA3
*/
#include "hash.h"
unsigned int SIZE;
/*
hashAdd.c

Function arguments: 
1. hash table with struct node* at each index,
2. license plate (string of chars)
3. first name (string of chars)
4. last name (string of chars)

Function method:
1. hash the license plate with hash function --- hash.c
2. create a new node with the information --- createNode.c (to be created...)
3. add the node to the hash table with listFrontAdd --- linked.c

*/

void hashAdd(struct node** hashTable,char* plate, char* first, char* last){
	unsigned int index = hash(plate);//gets hash of plate
	struct node* newNode = createNode(plate,first,last);//allocates and fills node
	hashTable[index]=listFrontAdd(hashTable[index],newNode);//add node to chain
}
//hash.c

/*

*/
unsigned int hash(unsigned char *str){
	unsigned int hash=0;
	char c;
	int i;
	for(i=0;i<strlen(str);i++){
		c = *str++;//assign char to c, then move to the next one in the string
		hash+=(c*(i+5));//macias algorithm
	}
	return hash % SIZE;//size is size of the hash table
}	

/*
hashDump.c
Prints contents of cell at index=cellNum
*/
void hashDump(struct node** hashTable, int cellNum){
	if(cellNum>=SIZE || cellNum<0){
		printf("Invalid cell number\n");
		return;
	}
	listPrint(hashTable[cellNum]);
}
//hashFind.c

/*
hashFind.c
void hashFind(struct node** hashTable, char* plate, char* first, char* last);
searches for a given plate in the hash table,
	1. if it is found, load the matching first and last name into first and last, 
			and return 1
	2. if not found, return 0

WARNING:
hashFind WILL SEGFAULT if it is passed merely pointers to chars or arrays of 
chars that are smaller than what is stored in the database. 
hashFind must be passed something like char myfirst[20],char mylast[20], 
otherwise strcpy will cause problems.
*/
int hashFind(struct node** hashTable, char* plate, char* first, char* last){
	unsigned int index=hash(plate);//hash the plate
	struct node* head = hashTable[index];
	if(listFind(head, plate, first, last)){//we found it
		return TRUE; //1
	}
	else {//NOT FOUND
		return FALSE; //0
	}
}

/*
hashFree
free all memory associated with this hash
*/
void hashFree(struct node** hashTable){
	int i;
	for(i=0;i<SIZE;i++){
		listFree(hashTable[i]);//free the chained lists and all their parts
	}
	free(hashTable);//free the table
}

//print the load in each cell of the hashTable
void hashLoad(struct node** hashTable){
	unsigned int i;
	for(i=0;i<SIZE;i++){
		printf("hashTable[%u] = %d\n",i,listLen(hashTable[i]));
	}
}
//hashInit.c

/*
hashInit.c 
Constructs an empty hash table, returning its address
*/
struct node** hashInit(int hashsize){
	int i;
	SIZE=hashsize;//SIZE is global inside of the hash functions
	struct node** hashTable = malloc(sizeof(struct node)*hashsize);
	if(hashTable==NULL){//malloc failed
		printf("Malloc failed!\n");
		exit(-1);
	}
	for(i=0;i<hashsize;i++){
		hashTable[i]=NULL;//initialize all sentinels to NULL 
		// this is fine because listFrontAdd (from linked.c)
		// will slip in a node in front of these NULLs, so no seg fault here
	}
	return hashTable;//return address of hashTable
}
