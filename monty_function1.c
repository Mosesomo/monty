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

/**
 *func_pint - prints the value at the top of the stack
 *@head: double head pointer of the stack
 *@line_counter: line number
 */

void func_pint(stack_t **head, unsigned int line_counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_counter);
		fclose(monty.file);
		free(monty.str);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
