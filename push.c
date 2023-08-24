#include "monty.h"

/**
 *func_push - function that add a node at the stack
 *@head: headpointer to the stack
 *@line_counter: count the line
 */

void func_push(stack_t **head, unsigned int line_counter)
{
	int i, j = 0, flag = 0;

	if (monty.arg)
	{
		if (monty.arg[0] == '-')
			j++;
		for (; monty.arg[j] != '\0'; j++)
		{
			if (monty.arg[j] > 57 || monty.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_counter);
			free(monty.str);
			fclose(monty.file);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		free(monty.str);
		fclose(monty.file);
		exit(EXIT_FAILURE);
	}
	i = atoi(monty.arg);
	if (monty.set_stack == 0)
		add_node(head, i);
}

