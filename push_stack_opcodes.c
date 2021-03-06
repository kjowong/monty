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
	new_node->next = NULL;
	if (*head != NULL)
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}
	*head = new_node;
	globals.retval = 0;
}

/**
 * push_node_mode - checks what mode it is (stack/queue) and calls the right
 * push node function depending on the mode
 * also checks argument and converts it to integer to be passed to push node
 * @head: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void push_node_mode(stack_t **head, unsigned int line_number)
{
	int n;

	if (!globals.push_val || !is_int(globals.push_val))
	{
		printf("L%u: usage: push integer\n", line_number);
		globals.retval = -1;
		return;
	}
	n = atoi(globals.push_val);
	if (globals.mode == 0)
		push_node(head, n);
	else
		push_node_end(head, n);
}

/**
 * push_node_end - adds a new node at the end of a doubly linked list
 * @head: head pointer
 * @n: new node interger to be added
 * Return: none
 */
void push_node_end(stack_t **head, int n)
{
	stack_t *new_node;
	stack_t *tmp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		globals.retval = -1;
		return;
	}
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		globals.retval = 0;
		return;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	new_node->prev = tmp;
	tmp->next = new_node;
	globals.retval = 0;
}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * This is the default behavior of the program.
 * @head: pointer to linked list
 * @line_number: number of lines in file
 */
void stack(__attribute__((unused)) stack_t **head,
	   __attribute__((unused)) unsigned int line_number)
{
	if (globals.mode == 0)
		return;
	globals.mode = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @head: pointer to linked list
 * @line_number: number of lines in file
 */
void queue(__attribute__((unused)) stack_t **head,
	   __attribute__((unused)) unsigned int line_number)
{
	if (globals.mode == 1)
		return;
	globals.mode = 1;
}
