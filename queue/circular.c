//Joshua Köhler - Queue implementation with circular array
#include<stdio.h>
#define SIZE 5
void enqueue(int val, int* circArray, int* frontIndex, int* tailIndex);//adds item to the back of the line
void init(int* frontIndex, int* tailIndex);
int dequeue(int* circArray, int* frontIndex, int* tailIndex);//returns value and removes oldest element
int isFull(int* circArray, int* frontIndex, int* tailIndex);
void print(int* circArray, int* frontIndex, int* tailIndex);
int isEmpty(int* frontIndex, int* tailIndex);//returns 1 for empty, 0 for non-empty
void enqueue(int val, int* circArray, int* frontIndex, int* tailIndex){
	if((((*tailIndex)+1)%SIZE)==(*frontIndex)){//The array is full
		printf("The array is full!\n");
		return;
	}
	circArray[(*tailIndex)]=val;//insert value into queue
	(*tailIndex)=((*tailIndex)+1)%SIZE;//increment tailIndex
}

/*
Check if circular array is full, return 1 for true (full)
0 for false (not full).
*/
int isFull(int* circArray, int* frontIndex, int* tailIndex){
	if((((*tailIndex)+1)%SIZE)==(*frontIndex)){//The array is full
		printf("The array is full!\n");
		return 1;
	}
	else{//queue is not full
		return 0;
	}
}

/*
Returns value from front of queue and removes it from queue
*/	
int dequeue(int* circArray, int* frontIndex, int* tailIndex){
	if(isEmpty(frontIndex, tailIndex)){//array is empty
		printf("Cannot dequeue, queue is empty.\n");
		return -1;
	}
	else{//go ahead and dequeue as intended
		int temp=(*frontIndex);//store index for pop
		(*frontIndex)=((*frontIndex)+1)%SIZE;//increment front index
		return circArray[temp];//return popped element
	}
}

/*
Returns 1 if empty, 0 if not empty
We know the array is empty if the frontIndex and tailIndex are the same.
These are only the same when the queue is empty.
*/	
int isEmpty(int* frontIndex, int* tailIndex){
	if((*frontIndex)==(*tailIndex)){//empty
		return 1;
	}
	else{//not empty
		return 0;
	}
}


/*
Print the queue
*/
void print(int* circArray, int* frontIndex, int* tailIndex){
	int i=(*frontIndex);//start with front of queue
	for(; i!=(*tailIndex); i=(i+1)%SIZE){//traverse queue till tail
		printf("%d <- ",circArray[i]);
	}
	printf("\n");
}

void init(int* frontIndex, int* tailIndex){
	(*frontIndex)=(*tailIndex)=0;
}
void main(void){
	int front; //front index (head)
	int back; //back index (tail)
	int cir[SIZE];//declare circular array with 10 spots
	init(&front,&back);
	enqueue(7,cir,&front,&back);
	print(cir,&front,&back);
	enqueue(1,cir,&front,&back);
	enqueue(8,cir,&front,&back);
	enqueue(9,cir,&front,&back);
	enqueue(3,cir,&front,&back);
	enqueue(2,cir,&front,&back);
	print(cir,&front,&back);
	enqueue(4,cir,&front,&back);
	print(cir,&front,&back);
	printf("dequeue -> %d\n",dequeue(cir,&front,&back));
	print(cir,&front,&back);
	printf("dequeue -> %d\n",dequeue(cir,&front,&back));
	print(cir,&front,&back);
	printf("dequeue -> %d\n",dequeue(cir,&front,&back));
	print(cir,&front,&back);
	printf("dequeue -> %d\n",dequeue(cir,&front,&back));
	print(cir,&front,&back);
}
