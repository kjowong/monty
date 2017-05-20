#include "monty.h"
/**
 * swap_first_second - swaps the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: the head pointer
 */
stack_t *swap_first_second(stack_t *h, size_t line_number)
{
	stack_t *tmp;

	if (list_len(h) < 2)
	{
		printf("L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = h;
	h = tmp->next;
	h->prev = NULL;
	tmp->next = h->next;
	tmp->prev = h;
	(tmp->next)->prev = tmp;
	return (h);
}
