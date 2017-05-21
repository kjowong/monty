#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void add(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;
	int sum;

	if (list_len(*h) < 2)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		globals.retval = -1;
		return;
	}
	tmp = (*h)->next;
	sum = (*h)->n + tmp->n;
	tmp->n = sum;
	pop_node(h, line_number);
	globals.retval = 0;
}

/**
 * sub - subtracts the top element of the stack from the 2nd top
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void sub(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	if (list_len(*h) < 2)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		globals.retval = -1;
		return;
	}
	tmp = (*h)->next;
	tmp->n -= (*h)->n;
	pop_node(h, line_number);
	globals.retval = 0;
}

/**
 * _div - divides the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void _div(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	if (list_len(*h) < 2)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		globals.retval = -1;
		return;
	}
	if ((*h)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		globals.retval = -1;
		return;
	}
	tmp = (*h)->next;
	tmp->n /= (*h)->n;
	pop_node(h, line_number);
	globals.retval = 0;
}

/**
 * mul - multiplies the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void mul(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;
	int result;

	if (list_len(*h) < 2)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		globals.retval = -1;
		return;
	}
	if ((*h)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		globals.retval = -1;
		return;
	}
	tmp = (*h)->next;
	result = (tmp->n * (*h)->n);
	pop_node(h, line_number);
	tmp->n = result;
	globals.retval = 0;
}

/**
 * mod - mods the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void mod(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;
	int result;

	if (list_len(*h) < 2)
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		globals.retval = -1;
		return;
	}
	if ((*h)->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		globals.retval = -1;
		return;
	}
	tmp = (*h)->next;
	result = (tmp->n % (*h)->n);
	pop_node(h, line_number);
	tmp->n = result;
	globals.retval = 0;
}
