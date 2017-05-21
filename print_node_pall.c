#include "monty.h"
/**
 * print_node_pall - function that prints all the elements of a list
 * @h: pointer to the constant stack_t head
 * Return: 0 on success, -1 on failure
 */
int print_node_pall(stack_t **h, __attribute__((unused)) size_t line_number)
{
	stack_t *temp;

	temp = *h;

	if (temp == NULL)
		return (-1);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (0);
}
