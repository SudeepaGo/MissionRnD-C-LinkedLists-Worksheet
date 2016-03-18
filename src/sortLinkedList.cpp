/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

void swap(int *, int *);

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	struct node *t1, *t2;
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;
	t1 = head;
	while (t1 != NULL) //Traversing nodes of linked list
	{
		t2 = t1->next;
		while (t2 != NULL) //Comparing the previous traversed node with all the next nodes
		{
			if (t1->num > t2->num)
			{
				swap(&t1->num, &t2->num); //swap the nodes if previous one is greater than the next one
			}
			t2 = t2->next;
		}
		t1 = t1->next;
	}
	return head;
}
void swap(int *num1, int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}