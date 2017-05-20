#include "monty.h"
/**
 * mul_first_second - adds the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void mul_first_second(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;
	int mul;

	if (list_len(*h) < 2)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		globals.retval = -1;
		return;
	}
	if ((*h)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		globals.retval = -1;
		return;
	}
	tmp = (*h)->next;
	mul = (tmp->n * (*h)->n);
	pop_node(h, line_number);
	tmp->n = mul;
	globals.retval = 0;
}
