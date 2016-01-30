/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node *p1, *p2;
	if (head==nullptr)
		return -1;
	p1 = p2 = head;
	if (p1->next == NULL)
		return p1->num;
	while (p2->next!=NULL)
	{
		if (p2->next->next != NULL)
		{
			p1 = p1->next;
			p2 = p2->next->next;
		}
		else
			break;
	}
	if (p2->next==NULL)
	{
		return p1->num;
	}
	else
	{
		return (p1->num + p1->next->num) / 2;
	}
}
