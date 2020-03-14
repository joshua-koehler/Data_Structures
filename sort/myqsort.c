/* Joshua Koehler - 2/13/2020 - myqsort.c
	This is a basic quick sort implementation, without any optimizations at the
	moment.  Adding Dijkstras 3-way partitioning would be a nice improvement.
	We take the first element here as the pivot.
	This function needs <stdlib.h> included.
	The user should include the library in their header file when using myqsort.
	Improvement: add shuffle function, use void* to make sort type independent
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static void swap(char* array, int i, int j);
static void myqsort(char* array, int lo, int hi);
static int partition(char* array, int lo, int hi);
static void printArray(char* array);
static void randomShuffle(char* array);

/*
Public function: void myqsort(char* array, int lo, int hi)
lo should be the index of the first element, hi is the index of the last element.
prototype of myqsort is in the header file myqsort.h
Sorts an array of chars with quick sort.
Max size of array is max number that an int can hold.
Using unsigned int will cause an error (the function relies on (0-1)<0)
Method:
Partition the array based off of the first character in the array
After this, the array is _____________Pivot_Value_____________
where everything to the right of the pivot_value is greater, and everything to
the left of the pivot value is lesser.
Then recursively partition the left side, then the right side.
*/
void myqsort(char* array, int lo, int hi){
	if(hi<=lo) return;//if we have only 1 element to partition, it is sorted
	int j = partition(array,lo,hi);//initial partition
	myqsort(array,lo,j-1);//recursively partition left
	myqsort(array,j+1,hi);//recursively partition right
}

/*
Partitions array, using the first element of the array of the partition element.
Upon exit everything to the left of index j is less than what is in index j,
and everything to the right of index j is greatern that what is in index j.
*/
static int partition(char* array, int lo, int hi){
	randomShuffle(array);//shuffle array to optimize qsort
	int i = lo;
	int j = hi+1;
	while(1){
		//scan i from left to right while entry is less than pivot
		while(array[++i]<array[lo]){//start by incrementing (don't use pivot)
			if(i==hi) break;
		}
		//scan j from right to left while entry is greater than pivot
		while(array[--j]>array[lo]){
			if(j==lo) break;
		}
		if(i >= j) break; //break once the pointers cross/overlap
		swap(array, i, j);
	}
	swap(array, lo, j);//swap the pivot with where the descending pointer ended up
	return j; //return index of item known to be in place
}

static void swap(char* array, int i, int j){
	char temp = array[i];
	array[i]=array[j];
	array[j]=temp;
}

static void randomShuffle(char* array){
	//give each index a random value and sort? too slow, and needs mergesort
	//swap their indexes with a rand%array_length O(n)
	//how
}

static void printArray(char* array){
	while(*array){
		printf("%c",*array++);
	}
	printf("\n");
}
/* 
Unit Test
void main(void){
	char i;
	char array[20];
	for(i=0;i<19;i++){
		array[i]=(rand()%25)+65;//random characters
	}
	array[++i]='\0';//NULL terminate
	printArray(array);
//	partition(array,0,19);
	myqsort(array,0,strlen(array)-1);
	printArray(array);
}
*/
