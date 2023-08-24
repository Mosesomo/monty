#include "monty.h"

/**
 *free_stack - function that frees a stack
 *@head: head pointer of the stack
 *
 */

void free_stack(stack_t *head)
{
	stack_t *temp = head;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
