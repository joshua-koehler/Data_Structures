/*
1/23/2020 - Joshua Köhler - Dynamic Array Implementation in C

A dynamic array (referred to as a vector in C++) is an array that will 
automatically change size when an addition would overflow the array.

realloc is a useful function that will resize the array (which we previously 
dynamically allocated) to a size of our choice (I selected a standard doubling
in size). 

The dynamic array is set up with a struct in C, which holds three things:
1. An array of our desired data type
2. A variable of type size_t holding the earliest free index
3. A variable of type size_t holding the size of the array

#2 and #3 are of type size_t, because they are used in malloc and realloc, 
which call for that type.

Below I have various functions to accomplish various goals common to data 
structures: Access, Insert, Delete, and Find.
*/

#define NOT_FOUND 0
#define FOUND 1
#include <stdio.h>
#include <stdlib.h>

// This struct holds our actual integer data in the int* array
// used should always be the next available index in the array
// size is the size of the array (the array will be resized)
typedef struct {
	int* array;
	size_t used;
	size_t size;
} DynamicArray;

/*
Pass this function a pointer to a structure of type DynamicArray, and the 
initial size for the array to be allocated.
*/
void initArray(DynamicArray *a, size_t initialSize){
	//allocate memory for an array of integers with initialSize
	a->array = malloc(initialSize * sizeof(int));
	if(a->array == NULL){
		printf("malloc failed!\n");
		return;
	}
	a->used=0;//array empty
	a->size=initialSize;//array has size of initialSize
}

/*
Insert a integer of value element into the array.
The element will be inserted in the first available index.

First the function will check if the array is full.
If it is full, it will reallocate double the space with realloc,
which automatically copies the information over.

After this conditional check, the insertion occurs.
The index (called used) will be incremented.

Finally, the dynamic memory reallocation is checked for failure
*/
void insertInArray(DynamicArray *a, int element){
	if(a->used == a->size){//array is full
		a->size *= 2; //double a->size of array
		//double size of array with dynamic reallocation
		a->array = realloc(a->array, a->size * sizeof(int));
		if(a->array == NULL){
			printf("realloc failed!\n");
			return;
		}
	}

	//this is like array[used] = element; used++;
	//add element to array, and increment used
	a->array[a->used++] = element;
}
/*
This function frees all dynamic memory allocated for the array.
Note that this does not free the entire structure, just the array.
To free the structure at the end of the main program (assuming it was
dynamically allocated, use free (see example on last line of main code).
*/
void freeArray(DynamicArray *a){
	free(a->array);
	a->array=NULL;
	a->used = a->size = 0;
}

/*
Deletes an element from the array, given the array, and the index of the element.
Checks are first made if an index is given for:
1. An index larger than the array
2. The index of an element that doesn't hold data yet

Provided the index is valid, loop through the elements from that index onward,
shifting all elements to the left.  Then, decrement used (first available slot).
*/

void deleteElementAtIndex(DynamicArray *a, int index){
	if(index>=a->size){
		printf("The index exceeds the size of the array.\n"); 
		return ;
	}
	if(index>=a->used){
		printf("There is no data there yet to delete!\n");
		return ;
	}
	for(; index < a->used; index++){//shift elements
		a->array[index]=a->array[index+1];//shift elements towards 0
	}
	a->used--;//decrement used
}

/*
Displays element from the array, given the array, and the index of the element.
Checks are first made if an index is given for:
1. An index larger than the array
2. The index of an element that doesn't hold data yet

Provided the index is valid, its data will be returned.
*/
int accessElementAtIndex(DynamicArray *a, int index){
	if(index>=a->size){
		printf("The index exceeds the size of the array.\n"); 
		return -2;
	}
	if(index>=a->used){
		printf("There is no data there yet!\n");
		return -1;
	}
	return a->array[index];//return element
}


void printArray(DynamicArray *a){
	int i;
	for(i=0; i < a->used; i++){
		printf("|%d| -> %d\n",i,a->array[i]);
	}
	printf("\n");
}

/*
Prints all occurences of an integer found in the array
*/
void findElement(DynamicArray *a, int element){
	int flag=NOT_FOUND;
	int i;
	for(i=0; i< a->used; i++){
		if(a->array[i]==element){//FOUND
			printf("The value %d was found at index %d\n",element,a->array[i]);
			flag=FOUND;
		}
	}
	if(flag==NOT_FOUND){
		printf("The value %d was not found in the dynamic array.\n",element);
	}
}
	
void main(void){
	DynamicArray* my=malloc(sizeof(DynamicArray));//dynamically allocate pointer
	//to a DynamicArray
	initArray(my,5);//initial size of 5
	insertInArray(my,1);
	printArray(my);
	insertInArray(my,2);
	printArray(my);
	insertInArray(my,3);
	printArray(my);
	insertInArray(my,4);
	printArray(my);
	insertInArray(my,5);
	printArray(my);
	insertInArray(my,6);
	printArray(my);
	insertInArray(my,7);
	printArray(my);

	findElement(my,5);
	findElement(my,1);
	findElement(my,7);
	findElement(my,234);

	accessElementAtIndex(my,1);		
	accessElementAtIndex(my,6);		
	accessElementAtIndex(my,0);		
	accessElementAtIndex(my,20);

	printf("delete at index 4\n");
	deleteElementAtIndex(my,4);
	printArray(my);
	printf("delete at index 0\n");
	deleteElementAtIndex(my,0);
	printArray(my);
	printf("delete at index 4\n");
	deleteElementAtIndex(my,4);
	printArray(my);
	
	freeArray(my);
	free(my);//free dynamically allocated pointer to a DynamicArray
}

