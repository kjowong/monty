#include "monty.h"
/**
 * push_node - adds a new node at the beginning of a list
 * @head: head pointer
 * @n: integer value of new node
 * Return: none
 */
void push_node(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		retval = -1;
		return;
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
	retval = 0;
}
