#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
	int value;
	Node * next;
};

Node * list_create() {
	Node * node = (Node*)malloc(sizeof(Node));
	node->value = 0;
	node->next = NULL;

	return node;
}

void list_add_value(Node * node, int value) {
	while (node->next != NULL) {
		node = node->next;		
	}

	Node* new_node = list_create();
	new_node->value = value;
	node->next = new_node;
}

void list_rem_value(Node* node, int value) {
	while (node->next != NULL) {
		if (node->next->value == value) {
			Node* aux = node->next;
			node->next = aux->next;
			free(aux);
			break;
		}
		node = node->next;
	}
	
}

void list_print(Node* node) {
	while (node->next != NULL) {
		printf("%d\t", node->next->value);
		node = node->next;
	}
	printf("\n");
}

int main(int argc, char ** argv) {
	Node* list = list_create();

	list_add_value(list, 10);
	list_add_value(list, 40);
	
	list_print(list);
	
	return 0;
}
