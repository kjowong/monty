#include "monty.h"
/**
 * mod_first_second - mods the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void mod_first_second(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;
	int mod;

	if (list_len(*h) < 2)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
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
	mod = (tmp->n % (*h)->n);
	pop_node(h, line_number);
	tmp->n = mod;
	globals.retval = 0;
}
