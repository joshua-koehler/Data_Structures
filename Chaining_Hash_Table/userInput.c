/*
userInput.c
This function parses user input, returning a command code for the main program.

There are 4 possible inputs, 3 of which are commands.
The only non-command input is a license plate.
When a user inputs a license plate:
1. It exists in the hash table - print the plate, and first and last name
2. It does not exist - print DOES NOT EXIST

Besides just entering in a plate number, there are 3 possible commands:
1. *LOAD - displays number of plates stored in each cell of the hash table
2. *DUMP - displays the contents of each cell of the hash table
3. *DUMP n - displays the contents of cell n of the hash table
*/
#include "hash.h"
int userInput(int* cell, char* plate){//pass in address of variable for indexing dump
	char str[120];
	char first[60];
	char second[60];	
	if(!fgets(str,120,stdin)){//get input, and check for EOF
		exit(0);//EOF given, so exit the program
	} 
	//parse input
	int scan=sscanf(str,"%s %s",first,second);
	
	if(scan==1){//only one argument given
		//check for specials
		if(!strcmp(first,"*LOAD")){//*LOAD was entered
			return LOAD;//defined in hash.h
		}
		else if(!strcmp(first,"*DUMP")){//*DUMP was entered
			return DUMPALL;
		}
		else{
			strcpy(plate,first);//copy over plate
			return PLATE;
		}
	}
	
	else if(scan==2){//two arguments given
		if(!strcmp(first,"*DUMP") && sscanf(second,"%d",cell)){//*DUMP <some int>
			return DUMPN;
		}
		else{//n was not an integer
			printf("%s is not a legal, in-range integer\nTry something between 0 and the hashTable size you input on the command line to start.\nIf you didn't input a hash table size to start, the default is 100, so choose n between 0 and 99\n",second);
		}
	}
	
	else{//invalid input
		printf("ERROR: Invalid input.\nInput a license plate, or one of the following commands:\n*LOAD - displays number of plates in each cell of hash table\n*DUMP - displays the contents of all the cells of the hash table\n*DUMP n - displays the contents of the nth cell of the hash table, where n is an integer\n");
		return INVALID;
	}
}
