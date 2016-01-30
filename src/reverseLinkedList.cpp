/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
void reverse(struct node **);
struct node * reverseLinkedList(struct node *head) {
	if (head==nullptr)
		return NULL;
	reverse(&head);
	return head;
}
void reverse(struct node **head)
{
	struct node *first, *n;
	if (*head == NULL)
		return;
	first = *head;
	n = first->next;
	if (n == NULL)
		return;
	reverse(&n);
	first->next->next = first;
	first->next = NULL;
	*head = n;
}
