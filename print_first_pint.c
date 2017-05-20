#include "monty.h"
/**
 * print_first_pint - prints all the elements of a dlistint_t list
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: the number of nodes
 */
void print_first_pint(stack_t *h, size_t line_number)
{
	if (h == NULL)
	{
		print("L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILIURE);
	}
	else
		printf("%d\n", h->n);
}
