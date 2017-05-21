#include "monty.h"
/**
 * print_all_pall - function that prints all the elements of a list
 * @h: pointer to the constant stack_t head
 * @line_num: line number in the file
 * Return: none
 */
void print_all_pall(stack_t **h, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	temp = *h;

	if (h == NULL || *h == NULL)
	{
		globals.retval = -1;
		return;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	globals.retval = 0;
}
