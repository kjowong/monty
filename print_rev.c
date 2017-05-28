#include "monty.h"
/**
 * print_rev - function that prints all the elements of a list
 * @h: pointer to the constant stack_t head
 * @line_num: line number in the file
 * Return: none
 */
void print_rev(stack_t **h, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	temp = *h;

	if (h == NULL || *h == NULL)
	{
		return;
	}
	while (temp != NULL)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
