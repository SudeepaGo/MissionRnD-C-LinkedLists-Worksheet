/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

void sortList(struct node*,int, int, int);

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	int n1=0, n2=0, n3=0;
	struct node *cur;
	cur = head;
	while (cur!= NULL)
	{
		if (cur->data == 0) n1++;
		if (cur->data == 1) n2++;
		if (cur->data == 2) n3++;
		cur = cur->next;
	}
	sortList(head, n1, n2, n3);
}
void sortList(struct node *head, int n1, int n2, int n3)
{
	int i;
	struct node *cur = head;
	while (cur != NULL)
	{
		for (i = 1; i <= n1; i++)
		{
			cur->data = 0;
			cur = cur->next;
		}
		for (i = 1; i <= n2; i++)
		{
			cur->data = 1;
			cur = cur->next;
		}
		for (i = 1; i <= n3; i++)
		{
			cur->data = 2;
			cur = cur->next;
		}
	}
}