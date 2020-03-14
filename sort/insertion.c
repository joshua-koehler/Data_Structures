#include<stdio.h>
#define SIZE 10
void printArr(int* arr, int size);
void insertionSort(int* arr, int size);
void insertAndShift(int* arr, int pulldex,int frontdex);

void main(void){
	int arr[SIZE]={1,4,63,21,64,6,3,2,5,13};
	printArr(arr,SIZE);
	insertionSort(arr,SIZE);
	printArr(arr,SIZE);
}

void printArr(int* arr, int size){
	printf("{");
	for(int i=0; i<size; ++i){
		printf("%d ",arr[i]);
	}
	printf("\b}\n");
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

/*
Sloppy first version 

void insertionSort(int* arr, int size){
	for(int i=1; i<size; ++i){//n-1 passes (first element is trivial)
		if(arr[i]<arr[i-1]){//out of order
			for(int j=2; (i-j)>=0; ++j){//check all elements below out-of-order element
				if(arr[i]>arr[i-j]){//insertion point found (it was the previous index)
					insertAndShift(arr,i,i-j+1);
					break;
				}
				if((i-j)==0){//insert at beginning
					insertAndShift(arr,i,0);
				}
			}
		}
	}
}

void insertAndShift(int* arr, int pulldex,int frontdex){
	int temp = arr[pulldex]; //save value to pull 
	while(pulldex!=frontdex){
		//shift elements to the right, starting closest to pulldex, working left
		// till we arrive at frontdex (then will swap this with temp)
		arr[pulldex]=arr[--pulldex];
	}
	//pulldex now equals frontdex
	arr[pulldex]=temp;//pull down value
}
*/

