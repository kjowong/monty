#include "monty.h"
/**
 * print_node_pall - function that prints all the elements of a list
 * @h: pointer to the constant stack_t head
 * Return: none
 */
void print_node_pall(stack_t **h, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	temp = *h;

	if (h == NULL || *h == NULL)
	{
		retval = -1;
		return;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	retval = 0;
}
