#include "hash.h"
/*	
readFile
Repeat the following till EOF:

1. get the line
2. parse the line
3. create a node
4. store node in the hash table
*/
void readFile(struct node** hashTable, char* fileName){
	char plate[20], first[20], last[20];
	unsigned int hash;
	int result;
	FILE* fptr = fopen(fileName,"r");
	
	if(fptr == NULL){
		printf("File read error\n");
		return;
	}
	
	//get a line
	char chunk[128];

	while(fgets(chunk, sizeof(chunk), fptr) !=NULL){//get line
		result=sscanf(chunk,"%s %s %s",plate,first,last);//parse line
		if(result!=3){
			printf("sscanf failed!\n");
		}
		hashAdd(hashTable,plate,first,last);
		printf("Plate: <%s> Name: %s,%s\n",plate,last,first);
	}

	fclose(fptr);
}
