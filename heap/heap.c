/*
Binary Max Heap Implemented with Array - Joshua Köhler - 3/14/2020
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
#define FALSE -1
#define ADDPOINTER 0
#define SWAP(x,y,T) do{T SWAP = x; x=y; y=SWAP;} while(0)
void printHeap(int* arr);
int heapAdd(int* arr, int num);
void upHeap(int* arr, int slot);
int pop(int* arr);
void downHeap(int* arr, int slot);


void main(void){
	int arr[SIZE];
	memset(arr,FALSE,sizeof(arr));//initialize all elements to FALSE (-1)
	//the first element is not part of the heap (ADDPOINTER=0)
	arr[ADDPOINTER]=1;//initialize add pointer to first available heap slot
	for(int i=1; i<SIZE; ++i){
		heapAdd(arr,i);
	}
	printHeap(arr);
	for(int i=1; i<SIZE; ++i)
		printf("%d ",pop(arr));
}

/* To delete/pop:
1. save element to pop (or throw away if deleting)
2. Replace top element with last element in heap (bottom right)
3. Down heap from this element
*/
int pop(int* arr){
	if(arr[ADDPOINTER] == 1) return FALSE; //Heap empty
	int ret = arr[1];//return this at end
	//step 2, adjusting addpointer slot
	arr[1]=arr[--arr[ADDPOINTER]];
	downHeap(arr,1);//down heap from top
	return ret;//return value
}

/* Down heap starting from top
1. If parent is greater than child, swap it with greatest child
2. Down heap from this swap path
*/
void downHeap(int* arr, int slot){
	//base case once leaf node node has no children
	if(slot*2 >= arr[ADDPOINTER]) return;
	else if(slot*2+1 >= arr[ADDPOINTER]){//only left child
		if(arr[slot*2]>arr[slot]){//left_child > parent
			SWAP(arr[slot],arr[slot*2],int);
			downHeap(arr, slot*2);
		}
		else return;
	}
	else{//has two childs, then swap with max child
		if(arr[slot*2]>arr[slot*2+1]){//left child bigger than right
			if(arr[slot*2]>arr[slot]){//left child bigger than parent
				SWAP(arr[slot*2],arr[slot],int);
				downHeap(arr,slot*2);
			}
			else return;//nodes are in proper position		
		}
		else{//right child bigger or equal to left
			if(arr[slot*2+1]>arr[slot]){//left child bigger than parent
				SWAP(arr[slot*2+1],arr[slot],int);
				downHeap(arr,slot*2+1);
			}
			else return;//nodes are in proper position
		}
	}
}
			
/* If child is greater than parent:
	 Swap and then make recursive call to check parent and grandparent
	 Else: return */
void upHeap(int* arr, int slot){
	if(slot<=1) return; //done
	else if(arr[slot]>arr[slot/2]){//child is greater than parent
		SWAP(arr[slot],arr[slot/2],int);
		upHeap(arr,slot/2);//recursively up-Heap
	}
}
	
/*Add to last slot, then upHeap (check child/parent sizes are 
correct and swap as needed)*/
int heapAdd(int* arr, int num){
	if(arr[ADDPOINTER]>=SIZE){ printf("Heap full\n"); return -1;}
	//1. add num at next available spot
	//2. increment next available spot
	arr[arr[ADDPOINTER]++]=num;//ugly but does both
	//3. Up heap to swap child/parent as needed
	upHeap(arr,arr[ADDPOINTER]-1);
}

//prints the heap Breadth First
void printHeap(int* arr){
	printf("{");
	for(int i=1; i<arr[ADDPOINTER]; ++i)
		printf("%d ",arr[i]);
	printf("\b}\n");
}
