#include "monty.h"
/**
 * div_first_second - adds the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void div_first_second(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;
	int div;

	if (list_len(*h) < 2)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		globals.retval = -1;
		return;
	}
	if ((*h)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		globals.retval = -1;
		return;
	}
	tmp = (*h)->next;
	div = tmp->n / (*h)->n;
	tmp->n = div;
	pop_node(h, line_number);
	globals.retval = 0;
}
