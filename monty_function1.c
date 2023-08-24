#include "monty.h"

/**
 *func_pall - function that prints the stack
 *@head: double pointer the stack
 *@count: unused line count
 */

void func_pall(stack_t **head, unsigned int count)
{
	(void)count;

	if (*head == NULL)
		return;
	while (*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
}
