#include "monty.h"
/**
 * add_first_second - adds the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: 0 on success, -1 on failure
 */
int add_first_second(stack_t **h, size_t line_number)
{
	stack_t *tmp;
	int sum;

	if (list_len(*h) < 2)
	{
		printf("L%lu: can't add, stack too short", line_number);
		return (-1);
	}
	tmp = (*h)->next;
	sum = (*h)->n + tmp->n;
	tmp->n = sum;
	pop_node(h, line_number);
	return (0);
}
