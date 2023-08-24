#include "monty.h"

/**
 *func_sub - function that substract nodes
 *@head: head pointer to the stack
 *@line_counter: line number
 */

void func_sub(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;
	int res, len = 0;

	temp = *head;
	for (; temp != NULL ; len++)
		temp = temp->next;
	if (len < 2)
	{
		fprintf(stderr, "L%d:  can't sub, stack too short\n", line_counter);
		fclose(monty.file);
		free(monty.arg);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	res = temp->next->n - temp->n;
	temp->next->n = res;
	*head = temp->next;
	free(temp);
}
