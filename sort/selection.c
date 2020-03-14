/* 
Selection Sort - Joshua Köhler - 3/12/2020
Each pass through an array, select the smallest value, and put it at the front 
index.  After each pass, increment the front index (everything in front of it
is now sorted).
*/
#include<stdio.h>
#define swap(x,y) do \ 
   { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
    } while(0)

/*
void swap(int* arr, int ind1, int ind2){
	int temp = arr[ind1];
	arr[ind1]=arr[ind2];
	arr[ind2]=temp;
}
*/

void selectionSort(int* arr, int length){
	int i,j,mindex;
	//make n passes, i is the first index of the unsorted portion of array
	for(i=0; i<length-1; ++i){
		mindex=i;//initialize minimum index to new front
		//j gets bigger as the items are sorted 
		//thus this pass gets smaller as the unsorted size of array shrinks
		for(j=i+1; j<length; ++j){
			if(arr[j] < arr[mindex]) mindex=j;//found new min, save its index
		}
		swap(arr[i],arr[mindex]);//swap min element with current front
	}
}
/*
Bad original version (works but not clean)
int* selection(int* array, int length){
	int original_length = length;
	int mindex, outdex, min;
	int output[length];//output array
	outdex = 0;//initialize output index
	for(int i=0; i<original_length; ++i){//make n passes
		mindex=0;//reset minimum index
		min=array[0];//reset minimum value
		for(int j=0; j<length; ++j){//make n - (# of passes complete)
			if(min > array[j]){//new min found
				min = array[j];//set new min
				mindex = j;//save index of this current min
			}
		}
		output[outdex++] = min;//append minimum element to output array
		swap(array,length-1,mindex);//move element to end of (shortened) array
		--length;//shorten array
	}
	for(int i=0; i<original_length; ++i){//O(n) copy ordered output to array
		array[i]=output[i];
	}
	return array;
}
*/

void printArray(int* arr, int length){
	for(int i=0; i<length; ++i){
		printf("%d, ",arr[i]);
	}
	printf("\n");
}

int main(void){
	int arr[10]={3,5,2,9,6,13,12,445,24,1};
	printArray(arr,10);
	selectionSort(arr,10),
	printArray(arr,10);
}

/*
enum myType {INTEGER, CHAR};
void* selectionSort(void* array,  int length, char type);
#define SWAP(index1, index2, array, Type) do { Type temp = array[index1]; array[index1] = array[index2]; array[index2] = temp;} while(0)

#define swap(x,y) do \ 
   { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
    } while(0)

return ((x < y) ? x : y)
 
if(x<y) return x;
else return y;

void printArrayInt(int* arr, int length){
	for(int i=0; i<length; ++i){
		printf("%d, ", arr[i]);
	}
}

void printArrayChar(char* arr, int length){
	for(int i=0; i<length; ++i){
		printf("%d, ", arr[i]);
	}
}

int main(void){
	int arr[5] = {2,3,1,5,4};
	printArrayInt(arr,5);
	char charr[5] = {'d','t','s','h','w'};
	printArrayChar(charr,5);
	arr = (int*)selectionSort(arr,5,INTEGER);
	printArrayInt(arr,5);
	charr = (int*)selectionSort(charr,5,CHAR);
	printArrayChar(charr,5);
}

void* selectionSort(void* array,  int length, char type){
	int outdex = 0;//index of output array
	switch(type){
		case INTEGER:
			//array of ints
			int output[length-1];//output array
			int min = *((int *)array);//set min to first value in array 
			int mindex = 0;//initialize index of minimum value to first element
			for(int i=0; i<length; ++i){
				for(int j=0; j<length; ++j){
					if(min > *((int *)array+j)){//new min
						min = *((int *)array+j);
						mindex = j;
					}
				}
				output[outdex++] = min;//append minimum element to output array
				SWAP(length-1,j,array,typeof(array[0]);//swap element with last
			}
		return output;

		case CHAR:
			//array of chars
			char output[length-1];//output array
			char min = *((char *)array);//set min to first value in array 
			char mindex = 0;//initialize index of minimum value to first element
			for(int i=0; i<length; ++i){
				for(int j=0; j<length; ++j){
					if(min > *((char *)array+j)){//new min
						min = *((char *)array+j);
						mindex = j;
					}
				}
				output[outdex++] = min;//append minimum element to output array
				SWAP(length-1,j,array,typeof(array[0]);//swap element with last
			}
		return output;
	}
}
*/
