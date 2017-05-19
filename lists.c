#include "monty.h"
/**
 * free_list - frees a list
 * @head: linked list to free
 * Return: none
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (1)
	{
		if (head == NULL)
			break;
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
}
