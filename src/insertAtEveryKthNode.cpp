/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node *start,*pre,*newnode;
	int c=0; 
	if ((head == nullptr) || (K<=0))
		return NULL;
	start = head;
	pre = head;
	while (start!=NULL)
	{
		if (c == K)
		{
			c = 0;
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = K;
			pre->next = newnode;
			newnode->next = start;
		}
		else
		{
			c++;
			pre = start;
			start = start->next;
		}
	}
	if (c == K)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->num = K;
		pre->next = newnode;
		newnode->next = NULL;
	}
	return head;
}
