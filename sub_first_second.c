#include "monty.h"
/**
 * sub_first_second - subtracts the top element of the stack from the second top 
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void sub_first_second(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	if (list_len(*h) < 2)
	{
		printf("L%u: sub't add, stack too short\n", line_number);
		globals.retval = -1;
		return;
	}
	tmp = (*h)->next;
	tmp->n -= (*h)->n;
	pop_node(h, line_number);
	globals.retval = 0;
}
