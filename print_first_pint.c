#include "monty.h"
/**
 * print_first_pint - prints all the elements of a dlistint_t list
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void print_first_pint(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		globals.retval = -1;
		return;
	}
	else
		printf("%d\n", (*h)->n);
	globals.retval = 0;
}
