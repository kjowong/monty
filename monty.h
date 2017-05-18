#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stlib.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void print_node_pall(stack_t *h);
void nop_node(stack_t *h);
stack_t *pop_node_opcode(stack_t **head, size_t line_number);
stack_t *swap_first_second(stack_t *h, size_t line_number);
stack_t *add_node_push(stack_t **head, int n);
void print_first_pint(stack_t *h, size_t line_number);
stack_t *add_first_second(stack_t *h, size_t line_number);
size_t list_len(stack_t *h);
#endif
