#include "monty.h"

/**
 *func_swap - function that swap top elements of the stack
 *@head: head pointer of the stack
 *@line_counter - line number
 */

void func_swap(stack_t **head, unsigned int line_counter)
{
	int val_swap;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_counter);
		fclose(monty.file);
		free(monty.str);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	val_swap = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = val_swap;
}
