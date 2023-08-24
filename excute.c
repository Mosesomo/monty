#include "monty.h"
#include <stddef.h>
#include <stdlib.h>

/**
 *execute - function excutes the monty instruction
 *@str: line pointer
 *@head: head pointer to stack
 *@counter: line number
 *@file: file pointer
 *
 *Return: alway 0 on success
 */

int execute(char *str, stack_t **head, unsigned int counter, FILE *file)
{
	instruction_t operation[] = {
		{"push", func_push},
		{"pall", func_pall},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *opt;

	opt = strtok(str, " \n\t");
	if (opt && opt[0] == '#')
		return (0);
	monty.arg = NULL;
	if (opt)
		monty.arg = strtok(NULL, " \n\t");

	while (operation[i].opcode && opt)
	{
		if (strcmp(opt, operation[i].opcode) == 0)
		{
			operation[i].f(head, counter);
			return (0);
		}
		i++;
	}
	if (opt && operation[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opt);
		fclose(file);
		free(str);
		exit(EXIT_FAILURE);
	}
	return (1);
}
