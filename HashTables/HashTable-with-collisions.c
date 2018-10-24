/*
* This is a simple hash table to demonstrate one way of dealing with collisions;
* The 'hash' algorithm is quite simple (just a modulo operation);
* Collisions are dealt by creating a linked list for every position in the table;
* When a hash value is inserted in a position that already has a member, 
* then the value is inserted in the end of that linked list;
* Some very specific values are preseted so you can change the value of m and 
* check for yourself how this implementation deals with collisions;
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>

 #define m 9
//#define m 11


 typedef struct element {
	int value;
	struct element *next;
} Element, *PointerToElement;

 typedef struct {
	PointerToElement linked_lists[m];
} Table;


 void initializeLinkedLists(Table *hashtable) {
	int i;
	for(i = 0; i < m; i++)
		hashtable->linked_lists[i] = NULL;
}

 int hash(int k) {
	return k % m;
}

 int searchValue(Table *hashtable, int value, PointerToElement *last) {
	int hash_result = hash(value);
	PointerToElement address = hashtable->linked_lists[hash_result];
	*last = NULL;
	
	while(address != NULL) {
		if(address->value == value)
			return hash_result;
		*last = address;
		address = address->next;
	}
	return -1;
}

 bool insertValue(Table *hashtable, int value) {
	PointerToElement last;
	if(searchValue(hashtable, value, &last) >= 0)
		return false;
	
	int hash_result = hash(value);
	PointerToElement address = (PointerToElement) malloc(sizeof(Element));
	address->value = value;
	address->next = NULL;
	
	if(last == NULL)
		hashtable->linked_lists[hash_result] = address;
	else
		last->next = address;
		
	return true;
}

 void generateTable(Table *hashtable) {
	insertValue(hashtable, 5);
	insertValue(hashtable, 28);
	insertValue(hashtable, 19);
	insertValue(hashtable, 15);
	insertValue(hashtable, 20);
	insertValue(hashtable, 33);
	insertValue(hashtable, 12);
	insertValue(hashtable, 7);
	insertValue(hashtable, 10);
}

 void printTable(Table *hashtable) {
	int i;
	PointerToElement address;
	for(i = 0; i < m; i++) {
		address = hashtable->linked_lists[i];
		printf("%d -> ", i);
		while(address != NULL) {
			printf("%d ", address->value);
			address = address->next;
		}
		printf("\n");
	}
}

 int main() {
	Table *hash_table = (Table *) malloc(sizeof(Table));
	initializeLinkedLists(hash_table);
	
	generateTable(hash_table);
	printf("Hash table with m = %d positions:\n\n", m);
	printTable(hash_table);
	
	return 0;
}
