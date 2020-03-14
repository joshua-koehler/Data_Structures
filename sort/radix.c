/*
Radix Sort - Joshua Köhler - 3/13/2020
*/
#include<stdio.h>
#define SIZE 10	
#define BITS_per_BYTE 8
#define HIGHEST_FLAG 128
void radix(char* arr, int size);
void printArr(char* arr, int size);

void main(void){
	char arr[SIZE] = {'c','b','s','e','f','g','w','s','x','t'};
	printArr(arr,SIZE);
	radix(arr,SIZE);
	printArr(arr,SIZE);
}


void radix(char* arr, int size){
	char hi[SIZE], lo[SIZE];//hi and low arrays
	int hindex, lindex; //hi and low index
	for(int i=1; i<=HIGHEST_FLAG; i=i<<1){//all bits, i is bit flag for HI
		hindex=lindex=0;
		for(int j=0; j<size; ++j){//all elements
			//sort each char by bit
			if(arr[j] & i) hi[hindex++] = arr[j]; //bit is hi
			else lo[lindex++] = arr[j];//bit is low
		}
		lo[lindex] = hi[hindex] = '\0';//null terminate
		lindex=hindex=-1;//reset indices (pre-incremented)
		while(lo[++lindex]!='\0'){//dump entries with lo bits
			arr[lindex]=lo[lindex];
		}
		while(hi[++hindex]!='\0'){//dump entries with hi bits
			arr[lindex++]=hi[hindex];
		}
	}
}
		
			
			

void printArr(char* arr, int size){
	printf("{");
	for(int i=0; i<size; ++i){
		printf("%c ",arr[i]);
	}
	printf("\b}\n");
}

	
	
	

