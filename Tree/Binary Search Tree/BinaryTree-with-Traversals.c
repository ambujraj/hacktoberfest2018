/*
* This is an example of a Binary Search Tree (without deletion) that uses random keys to generate itself;
* All tree traversals are implemented: pre-order, in-order and post-ordem;
* A generic print function that uses parenthesis to stablish hierarchy is also implemented;
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>
#include<time.h>

#define max 10
#define range 60


typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node, *PointerToNode;


PointerToNode initializeTree() {
	return NULL;
}

PointerToNode newNode(int k) {
	PointerToNode new_node = (PointerToNode) malloc(sizeof(Node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->key = k;
	return new_node;
}

PointerToNode insertKey(PointerToNode root, PointerToNode node) {
	if(!root)
		return node;
	if(node->key < root->key)
		root->left = insertKey(root->left, node);
	else
		root->right = insertKey(root->right, node);
	return root;
}

PointerToNode binarySearch(PointerToNode root, int k) {
	if(!root)
		return NULL;
	if(root->key == k)
		return root;
	if(root->key > k)
		return binarySearch(root->left, k);
	return binarySearch(root->right, k);
}

void printFormatedTree(PointerToNode root) {
	if(root) {
		printf("%d", root->key);
		printf("(");
		printFormatedTree(root->left);
		printFormatedTree(root->right);
		printf(")");
	}
}

void preOrder(PointerToNode root) {
	if(root) {
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(PointerToNode root) {
	if(root) {
		inOrder(root->left);
		printf("%d ", root->key);
		inOrder(root->right);
	}
}

void postOrder(PointerToNode root) {
	if(root) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->key);
	}
}


int generateRandomKey() {
	return rand() % range;
}

PointerToNode generateRandomTree(PointerToNode root) {
	int i;
	for(i = 0; i < max; i++) {
		int rnd = generateRandomKey();
		PointerToNode new_node = binarySearch(root, rnd);
		if(!new_node) {
			new_node = newNode(rnd);
			root = insertKey(root, new_node);
		} 
		else i--;
	}
	return root;	
}


int main() {
	srand(time(NULL));
	
	PointerToNode r = initializeTree();
	r = generateRandomTree(r);
	
	printf("Formated tree: ");
	printFormatedTree(r);
	printf("\n\n");
	
	printf("Pre-order: ");
	preOrder(r);
	printf("\n\n");
	
	printf("In-order: ");
	inOrder(r);
	printf("\n\n");
	
	printf("Post-order: ");
	postOrder(r);
	printf("\n\n");
	
	return 0;
}

