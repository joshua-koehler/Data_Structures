#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
Given a rod, it can be split into sections of 1 inch chunks.
Each chunk has a different (non-linear) value.
Find the max value that can be obtained from a section.
*/
#define SIZE 5

typedef struct {
	int length;
	int value;
} piece;

int mem[200];//memoization array
piece* arr[SIZE];//array of lengths and values

piece* newPiece(int length, int val);
int rod(int length);

int main(void){
	memset(mem,-1,sizeof(mem));
	mem[0]=0;//basecase
	piece *a, *b, *c, *d, *e;
	a = newPiece(1,1);
	b = newPiece(2,3);
	c = newPiece(3,6);
	d = newPiece(4,7);
	e = newPiece(6,10);
	//arr = {a,b,c,d,e};
	arr[0]=a;
	arr[1]=b;
	arr[2]=c;
	arr[3]=d;
	arr[4]=e;
	
	for(int i=0; i<100; ++i){
		printf("Max value from length %d = $%d\n",i,rod(i));
	}
	//free memory
	free(a); free=(b); free(c); free(d); free(e);
}

int rod(int length){
	if(length==0) return 0;//perfect finish
	if(length<0) return -10;//invalid final length, subtract largest value
	if(mem[length] != -1) return mem[length];//memoization
	
	//get max
	int temp, max=0;
	
	for(int i=0; i<SIZE; ++i){
		if((length-arr[i]->length) < 0) continue;//skip this invalid option
		else if((temp = mem[length-arr[i]->length])!=-1){//memoized
			temp+=arr[i]->value;
		}
		else if((temp = rod(length-arr[i]->length)+arr[i]->value)){}//recursive
		else{printf("Error\n");}//should never be called
	
		if(temp>max) max=temp;
	}
	mem[length]=max;
	return max;
}
		

piece* newPiece(int length, int val){
	piece* temp = malloc(sizeof(piece));
	temp->length = length;
	temp->value = val;
}
	



