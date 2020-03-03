/*
You can fill a knapsack with items up to a certain weight.
You can take as many of each item as you want (must be a whole number of items).
Write a function, which, given a certain max weight, finds the highest value.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 3
typedef struct myItem{
	int weight;
	int value;
} item;

int mem[100];
int knap(int weight, item** array, int size);
item* newNode(int weight, int value);

int main(void){
	memset(mem,-1,sizeof(mem));//set all values in mem to -1
	// Set up table of items
	item *pc, *tablet, *watch;
	pc = newNode(4,9);
	tablet = newNode(3,6);
	watch = newNode(1,1);
	
	item* array[SIZE] = {pc,tablet,watch};//array of items

	for(int i=0; i<10; ++i){
		printf("Max value with weight %d: %d\n",i,knap(i, array, SIZE));
	}
	free(pc); free(tablet); free(watch); //free items
}

int knap(int weight, item** arr, int size){
	if(weight<0) return -1000000;//big negative ensures this value is dropped
	if(weight==0) return 0;//basecase
	int maxval=0;
	int temp, i;
	for(i=0; i<SIZE; ++i){
		if(mem[weight]!=-1){//already computed
			return mem[weight];//return cached value
		}
		else if((temp = knap(weight-arr[i]->weight, arr, SIZE) + arr[i]->value) > maxval){
			maxval=temp;
		}
		else{
		}
	}
	mem[weight]=maxval;
	return maxval;
}
	
item* newNode(int weight, int value){
	item* temp = malloc(sizeof(item));
	temp->weight=weight;
	temp->value=value;
	return temp;
}
