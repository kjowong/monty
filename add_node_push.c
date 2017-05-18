#include "monty.h"
/**
 * add_node_push - adds a new node at the beginning of a list
 * @head: head pointer
 * @n: integer value of new node
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_node_push(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
