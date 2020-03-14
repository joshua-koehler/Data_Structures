#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c-(int)'a')
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
typedef struct mytrie{
	struct mytrie* children[ALPHABET_SIZE];
	bool iseow;//is end of word
} trie;

trie* getNode(void){
	trie* node = NULL;
	node = malloc(sizeof(trie));
	if(!node){//malloc error 
		printf("Malloc fail\n"); exit(-1);
	}
	for(int i=0; i<ALPHABET_SIZE; ++i)//set all nodes
		node->children[i] = NULL;//set children to NULL
	node->iseow = false;
	return node;
}

void tradd(trie* root,char* str){
	int level,index,length=strlen(str);
	for(level=0; level<length; ++level){
		index = CHAR_TO_INDEX(str[level]);
		if(!root->children[index])//no node for this char
			root->children[index]=getNode();
		root=root->children[index];
	}
	root->iseow=true;
}

bool trearch(trie* root, char* str){
	int level,index,length=strlen(str);
	for(level=0; level<length; ++level){//for every char
		index = CHAR_TO_INDEX(str[level]);
		if(!root->children[index]) return false;//not found
		root=root->children[index];
	}
	return (root && root->iseow);//true is non-null and eow 
}
/*
1. This trie delete function is not done it should manage:
2. Key may not be there in trie. Delete operation should not modify trie.
3. Key present as unique key (no part of key contains another key (prefix), nor the key itself is prefix of another key in trie). Delete all the nodes.
4. Key is prefix key of another long key in trie. Unmark the leaf node.
5. Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key until first leaf node of longest prefix key.

bool trelete(trie root, char* str){
	int level,index,length=strlen(str);
	for(level=0; level<length; ++level){//for every char
		index = CHAR_TO_INDEX(str[level]);
		if(!root->children[index]) return false;//not found
		root=root->children[index];
	}
	for(int i=0; i<ALPHABET_SIZE; ++i){
		if(root->children[i]){//shared node
			root->iseow = false;//simply change flag
			return true;
		}
	}
	//node is not shared, go ahead and free it
	free(root);
	return true;
}
*/
	
void main(void){
	trie* head = malloc(sizeof(trie));//initialize
	tradd(head,"abc");
	tradd(head,"t");
	tradd(head,"ab");
	tradd(head,"abd");
	(trearch(head,"abc") == 1) ? printf("abc is in trie\n") : printf("abc is not in trie\n");
	(trearch(head,"cat") == 1) ? printf("cat is in trie\n") : printf("cat is not in trie\n");
	(trearch(head,"ab") == 1) ? printf("ab is in trie\n") : printf("ab is not in trie\n");
	/*
	printf("deleting abc");
	trelete(head,"abc");
	(trearch(head,"abc") == 1) ? printf("abc is in trie\n") : printf("abc is not in trie\n");
	*/
}
