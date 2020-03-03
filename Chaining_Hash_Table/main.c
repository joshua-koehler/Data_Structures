//main.c
/*
This main.c program has two stages:
1. Load in a database
2. Run user commands till user inputs EOF
*/
#include "hash.h"
void main(int argc, char** argv){
	struct node** hashTable;
	unsigned int size=100;//default size
	unsigned int cell;//keeps track of which cell to dump with *DUMP n
	unsigned int cmd;//keeps track of user input command
	unsigned int i;//for loop
	char plate[20];//for license plate input
	char first[20];
	char last[20];
	if(argc==2){
		hashTable=hashInit(size);
		readFile(hashTable,argv[1]);
	}
	else if(argc==3){
		sscanf(argv[2],"%u",&size);//store the numerical input in global size
		hashTable=hashInit(size);
		readFile(hashTable,argv[1]);
	}
	else{
		printf("ERROR: invalid argument or no argument\n");
		exit(1);
	}

	//now that the hash table is loaded, we run user commands
	while(1){//userInput will cause the break internally upon user entry of EOF
		printf("Enter command or plate: ");
		cmd=userInput(&cell,plate);
		if(cmd==END){//free and exit the program
			hashFree(hashTable);//free memory
			exit(0);
		}
		else if(cmd==INVALID){//try again
			continue;//try again
		}
		else if(cmd==PLATE){//look up plate
			if(hashFind(hashTable,plate,first,last)==TRUE){//found
				printf("First name: %s\n",first);
				printf("Last name: %s\n",last);
				continue;//get another input
			}
			else{
				printf("Plate not found.\n");
				continue;//get another input
			}
		}
		else if(cmd==LOAD){//display number of nodes per cell
			hashLoad(hashTable);//print load in each cell
		}
		else if(cmd==DUMPALL){//display contents of entire hash table
			for(i=0;i<size;i++){//loop through whole table
				hashDump(hashTable, i);//dump each entry
			}
		}
		else if(cmd==DUMPN){//display contents of a specific cell of the hash table
			hashDump(hashTable,cell);//dump only this cell
		}
	}
}
