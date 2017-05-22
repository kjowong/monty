#include "monty.h"
/**
 * swap_first_second - swaps the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void swap_first_second(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	if (list_len(*h) < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		retval = -1;
		return;
	}

	tmp = *h;
	*h = tmp->next;
	tmp->next = (*h)->next;
	(*h)->next = tmp;
	tmp->prev = *h;
	(*h)->prev = NULL;
	(tmp->next)->prev = tmp;
	retval = 0;
}
