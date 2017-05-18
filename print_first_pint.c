#include "monty.h"
/**
 * print_first_pint - prints all the elements of a dlistint_t list
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: 0 is success, -1 on failure
 */
int print_first_pint(stack_t **h, size_t line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%d: can't pint, stack empty", line_number);
		return (-1);
	}
	else
		printf("%d\n", (*h)->n);
	return (0);
}
