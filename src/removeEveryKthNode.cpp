/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

int calculateLength(struct node **);
struct node* deleteKthNode(struct node **,int);

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	int p, l;
	if (head == NULL || K <= 0 || K == 1)
		return NULL;
	int len = calculateLength(&head);
	if (K > len) return head;

		head=deleteKthNode(&head, K);
		len = calculateLength(&head);
		l = K - 1;
		p = K + l;
		while (p <= len) //for calculating the position of every kth node
		{
			head=deleteKthNode(&head, p);
			len = calculateLength(&head);
			p = p + l;
		}
		return head;
}
int calculateLength(struct node **head)
{
	struct node *cur = *head;
	int n=0;
	while (cur != NULL)
	{
		n++;
		cur = cur->next;
	}
	return n;
}
struct node* deleteKthNode(struct node **head,int l)
{
	node *current_node = *head;     // To Traverse The linked list.

	node *previous_node = NULL;
	for (int i = 0; i<l; i++)            // Traverse to the nth node
	{
		previous_node = current_node;
		current_node = current_node->next;
	}

	// current_node contains the nth element
	// previous_node contains the (n-1)th element
		previous_node->next = current_node->next;
	free(current_node);         // Delete the nth node 
	return *head;
}