#include "monty.h"
/**
 * add_first_second - adds the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: the head pointer
 */
stack_t *add_first_second(stack_t *h, size_t line_number)
{
	stack_t *tmp;
	int sum;

	if (list_len(h) < 2)
	{
		printf("L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = h->next;
	sum = h->n + tmp->n;
	tmp->n = sum;
	h = pop_node_opcode(h, line_number)
	return (h);
}
