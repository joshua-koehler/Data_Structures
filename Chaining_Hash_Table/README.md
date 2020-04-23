This is a program that hashes a database of license plates and names.  

After reading in a file containing plate/name pairs, the program allows the user to enter a license plate, and it will display the corresponding name.

The user can also enter commands instead of a license plate, to examine the internal data structure of the hash table.

Program can be run in two ways:

1. plate database_name //size defaults to 100
2. plate database_name size

else return an ERROR MESSAGE

Data is processed from the database one line at a time:\
SQL-101 Johann Müller\
QJF-436 Jurgen Heck\
.
.
.
etc.

USER COMMANDS:
*LOAD //displays number of plates in each cell of the hash table
*DUMP //Display contents of each cell of the hash table
*DUMP n //where n is an integer, display contents of cell n

user exits with CTRL+D //EOF

Linked List:
struct node{
	char* plate;
	char* first;
	char* list;
	struct node* next;
};





