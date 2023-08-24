#include "monty.h"

/**
 *func_pall - function that prints the stack
 *@head: double pointer the stack
 *@count: unused line count
 */

void func_pall(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	if (*head == NULL)
		return;
	temp = *head;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
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
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 *func_pop - function that  removes the top element of the stack
 *@head: doubly pointer to the stack
 *@line_counter: line number
 */

void func_pop(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;

	if (*head == NULL)
	{
		monty.set_stack = 0;
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_counter);
		fclose(monty.file);
		free(monty.str);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
