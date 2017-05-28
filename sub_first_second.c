#include "monty.h"
/**
 * sub_first_second - subtracts the top element of the stack from the 2nd top
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void sub_first_second(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;
	int sub;

	if (list_len(*h) < 2)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		globals.retval = -1;
		return;
	}
	tmp = (*h)->next;
	sub = (tmp->n - (*h)->n);
	temp->n = sub;
	pop_node(h, line_number);
	globals.retval = 0;
}
