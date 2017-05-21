#include "monty.h"
/**
 * swap_first_second - swaps the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: 0 on success, -1 on failure
 */
int swap_first_second(stack_t **h, size_t line_number)
{
	stack_t *tmp;

	if (list_len(*h) < 2)
	{
		printf("L%d: can't swap, stack too short", line_number);
		return (-1);
	}

	tmp = *h;
	*h = tmp->next;
	(*h)->prev = NULL;
	tmp->next = (*h)->next;
	tmp->prev = *h;
	(tmp->next)->prev = tmp;
	return (0);
}
