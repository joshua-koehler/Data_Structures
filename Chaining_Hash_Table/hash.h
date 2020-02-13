//hash.h
#ifndef CLASSY
#define CLASSY //not only is this header file classy, it defines classy
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//these six defines are codes that userInput function will pass back to main
#define INVALID -1
#define PLATE 0
#define LOAD 1
#define DUMPALL 2
#define DUMPN 3
#define END 4

#define SUCCESS 1
#define FAILURE 0
#define TRUE 1
#define FALSE 0
extern unsigned int SIZE;
struct node{
	char* plate;//license plate
	char* first;//first name
	char* last;//last name
	struct node* next;//pointer to next node
};
int userInput(int* cell,char* plate);
void readFile(struct node** hashTable, char* fileName);
void hashAdd(struct node** hashTable, char* plate, char* first, char* last);
void hashLoad(struct node** hashTable);
void hashFree(struct node** hashTable);
void hashDump(struct node** hashTable, int cellNum);
struct node** hashInit(int size);
int hashFind(struct node** hashTable, char* plate, char* first, char* last);
unsigned int hash(unsigned char* str); 
/* From linked.c */
struct node* listFree(struct node* head);
int listFind(struct node* sent, char* plate, char* first, char* last);
struct node* listInit(void);
int listLen(struct node* head);
int listIsEmpty(struct node* head);
struct node* listFrontAdd(struct node* head,struct node* newNode);
int listNodeDelete(struct node* delete, struct node** head);
struct node* createNode(char* plate,char* first, char* last);
void listPrint(struct node* head);
#endif
