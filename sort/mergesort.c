//Merge Sort Implementation - Joshua Köhler - 1-29-2020
#include<stdio.h>
#include<stdlib.h>
void mergesort(int* array,int length);
void merge(int *a, int* l, int leftCount,int *r,int rightCount);
void printArray(int* arr, int size);

/*
This sort method uses recursion. Time complexity is O(n*log(n))
The basic method is:

Split an array into two arrays, then split these arrays... until each array has
one element.

After all these arrays have been split recursively, work your way back up, 
merging the results in sorted order as you go.
*/

/*
mergesort is the function that will be called in a main program

It takes two arguments, an unsorted array, and its length.

It will sort the array from least to greatest.

The function returns when an array is of size 1
Otherwise, it splits the array into two dynamically allocated arrays left/right
It then fills these arrays with the left/right side of the main array.
Then, it makes a recursive call to the left array, 
followed by a recursive call to the right array.
It then calls merge to work its way back up the recursive tree,
sorting the elements on the way back up.
Finally, it frees all the sub-trees on the heap.
*/
void mergesort(int* array,int length){
	int i, mid,*left,*right;
	if(length<2)return;//basecase, with only one element, no sort is necessary
	mid=length/2;//mid is rounded down (truncated)
	left=malloc(mid*sizeof(int));
	right=malloc((length-mid)*sizeof(int));

	for(i=0;i<mid;i++){//fill left array
		left[i]=array[i];
	}
	for(i=mid;i<length;i++){//fill right array
		right[i-mid]=array[i];
	}
	mergesort(left,mid);
	mergesort(right,length-mid);
	merge(array,left,mid,right,length-mid);
	free(left);
	free(right);
}

/*
merge exists to be used by mergesort

The function takes 5 inputs:
int* a is the array that will be merged into
int* l is the left sub-array
int leftCount is the size of the left array
int* r is the right sub-array
int rightCount is the size of the right array

It sorts the left elements with the right elements with the following method:
Keep track of left index, right index, and array index. (initialize to 0)

If the first left element is smaller than the first right element,
choose the first left element to be the first element in the array.
Then increment the left index and array index, and compare again.

If the first right element is smaller than the first left element,
choose the first right element to be the first element in the array.
Then increment the right index and array index, and compare again.

If either the left or right index hits its upper limit,
then we don't compare anymore, we just dump the remainder of the right/left
sub-array into the main array in order, as these elements are in order, and 
all bigger than the last element of the exhausted sub-array.
*/
void merge(int *a, int* l, int leftCount,int *r,int rightCount){
	int i,j,k;
	i=j=k=0;
	//i - to mark the index of the left subarray l
	//j - to mark the index of the right subarray r
	//k - to mark the index of the merged subarray a

	while(i<leftCount && j<rightCount){//both left and right arrays contain stuff
		if(l[i]<=r[j]){//if left element is smaller 
			 a[k++] = l[i++];//insert and increment left index and merged index		
		}
		else{//right element is smaller
			a[k++] = r[j++];//insert and increment right index and merged index
		}
	}
	while(i<leftCount){//left array contains stuff
		a[k++]=l[i++];
	}
	while(j<rightCount){//right array contains stuff
		a[k++]=r[j++];
	}
}
void printArray(int* arr, int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d, ",arr[i]);
	}
	printf("\n");
}

/*
Test code for merge sort
*/
void main(void){
	int arr[10]={1,5,8,3,9,2,4,7,6,0};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,arr_size);
	printf("Sorting...\n");
	mergesort(arr,10);
	printArray(arr,10);
}
	


