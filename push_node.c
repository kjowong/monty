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
		globals.retval = -1;
		return;
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (new_node->next)
		new_node->next->prev = new_node;
	*head = new_node;
	globals.retval = 0;
}
/**
 * push_node_mode - checks what mode it is (stack/queue) and calls the right
 * push_node function depending on the mode
 * also checks argument and converts it to integer to be passed to push node
 * @head: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void push_node_mode(stack_t **head, unsigned int line_number)
{
	int n;

	if (!globals.push_val && !is_int(globals.push_val))
	{
		printf("L%u: usage: push integer\n", line_number);
		globals.retval = -1;
		return;
	}
	n = atoi(globals.push_val);
	if (globals.mode == 0)
		push_node(head, n);
	else
		push_node(head, n);
}
