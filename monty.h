#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
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

/**
 * struct global_s - hold global variables
 * @retval: return value of functions
 * @mode: mode of list
 * @command: byte code command
 * @push_val: argument to push command
 */
typedef struct global_s
{
	int retval;
	int mode;
	char *command;
	char *push_val;
} global_t;

/* global variables */
extern global_t globals;
global_t globals;

/* print stack opcodes */
void pall(stack_t **h, unsigned int line_number);
void pint(stack_t **h, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);
void print_rev(stack_t **h, unsigned int line_num);

/* math stack opcodes */
void add(stack_t **h, unsigned int line_number);
void sub(stack_t **h, unsigned int line_number);
void _div(stack_t **h, unsigned int line_number);
void mul(stack_t **h, unsigned int line_number);
void mod(stack_t **h, unsigned int line_number);

void nop_node(stack_t **h, unsigned int line_number);
void swap_first_second(stack_t **h, unsigned int line_number);

void pop_node(stack_t **head, unsigned int line_number);
void push_node(stack_t **head, int n);
void pchar(stack_t **h, unsigned int line_number);
void pstr(stack_t **h, unsigned int line_number);
void stack(stack_t **h, unsigned int line_num);
void queue(stack_t **h, unsigned int line_num);

void push_node_mode(stack_t **head, unsigned int line_number);
void push_node_end(stack_t **head, int n);

void tokenize(char *line);
int is_empty(char *str);
int is_int(char *str);

int find_opcode(stack_t **head, unsigned int line_number);
void free_array(char **array);
void free_list(stack_t *head);
size_t list_len(stack_t *h);
#endif
