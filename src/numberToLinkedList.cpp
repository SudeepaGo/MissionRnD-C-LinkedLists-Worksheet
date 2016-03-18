/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

void push(struct node **, int);
struct node *newNode(int);

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	int r;
	struct node *head = NULL;
		if (N == 0)
		{
			head = newNode(N);
		}
		else
		{
		   if (N < 0)
		    	N = N - N * 2;
			while (N > 0)
			{
				r = N % 10;
				push(&head, r);
				N = N / 10;
			}
		}
	return head;
}
void push(struct node** head, int data)
{
	struct node* new_node = newNode(data);
	new_node->next = (*head);
	(*head) = new_node;
}
struct node *newNode(int data)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->num = data;
	new_node->next = NULL;
	return new_node;
}