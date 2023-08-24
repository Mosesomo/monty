#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *strut monty_t - defines global variables
 *@arg: value
 *@file: pointer to monty file
 *@line: line content
 *@set_stack: checks for stack
 */

typedef struct monty_t
{
	char *arg;
	FILE *file;
	char *str;
	int set_stack;
} monty_s;

extern monty_s monty;

int execute(char *str, stack_t **head, unsigned int counter, FILE *file);
void func_push(stack_t **head,unsigned  int line_counter);
void func_pall(stack_t **head, unsigned int count);
void add_node(stack_t **head, int n);


#endif
