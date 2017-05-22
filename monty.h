#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
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
extern int retval;
void print_node_pall(stack_t **h, unsigned int line_number);
void nop_node(stack_t **h, unsigned int line_number);
void pop_node(stack_t **head, unsigned int line_number);
void swap_first_second(stack_t **h, unsigned int line_number);
void push_node(stack_t **head, int n);
void print_first_pint(stack_t **h, unsigned int line_number);
void add_first_second(stack_t **h, unsigned int line_number);
size_t list_len(stack_t *h);
int find_opcode(char **token, unsigned int line_number, stack_t **head);
void free_array(char **array);
void free_list(stack_t *head);
char **tokenize(char *line, unsigned int line_number);
int is_empty(char *str);
int is_int(char *str);
#endif
