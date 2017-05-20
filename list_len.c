#include "monty.h"
/**
 * list_len - returns the number of elements in a list
 * @h: head pointer
 * Return: the number of elements
 */
size_t list_len(stack_t *h)
{
	stack_t *tmp;
	size_t count;

	tmp = h;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
