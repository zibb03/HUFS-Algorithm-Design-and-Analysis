// Implement Linked List
// Âü°í: https://coder-in-war.tistory.com/entry/C-17-%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8-%EA%B5%AC%EC%A1%B0%EC%B2%B4-Linked-List

#include <stdio.h>
#include <stdlib.h> // For malloc, free function

typedef struct NODE {
	int data;
	struct NODE* link;
}node;

int main(void) {
	// Create head node
	node* head = (node*)malloc(sizeof(node));  // Allocation
	head->link = NULL;

	// Create node
	node* node1 = (node*)malloc(sizeof(node)); // Allocation
	node1->link = head->link; // Make node1's link to NULL
	node1->data = 10;
	head->link = node1; // Link node 1 to head (head node -> node1)

	// Create node 
	node* node2 = (node*)malloc(sizeof(node)); // Allocation
	node2->link = node1->link; // Make node2's link to NULL
	node2->data = 20;
	node1->link = node2; // Link node 2 to 1 (head node -> node1 -> node2)

	// Create node 
	node* node3 = (node*)malloc(sizeof(node)); // Allocation
	node3->link = node2->link; // Make node3's link to NULL
	node3->data = 30;
	node2->link = node3; // Link node 3 to 2 (head node -> node1 -> node2 -> node3)

	// Print all node
	node* curr = head->link;
	while (curr != NULL) {
		printf("%d\n", curr->data);
		curr = curr->link;
	}

	// Delete middle node (node2)
	node1->link = node3; // Link node 3 to 1 (head node -> node1 -> node3)
	free(node2);

	// Print all node
	node* curr2 = head->link;
	while (curr2 != NULL) {
		printf("%d\n", curr2->data);
		curr2 = curr2->link;
	}

	// Free up memory
	free(head);
	free(node1);
	free(node3);
	return 0;
}