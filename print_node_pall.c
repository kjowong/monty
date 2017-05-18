#include "monty.h"
/**
 * print_node_pall - function that prints all the elements of a list
 * @h: pointer to the constant stack_t head
 */
void print_node_pall(stack_t *h)
{
	stack_t *temp;

	temp = h;

	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
