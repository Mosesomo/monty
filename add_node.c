#include "monty.h"

/**
 *add_node - function that adds a node in stack
 *@head: head pointer of the stack
 *@n: node to be added
 */

void add_node(stack_t **head, int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *head;

	if (*head)
		(*head)->prev = newnode;
	*head = newnode;

}

