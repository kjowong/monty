#include "monty.h"
/**
  * pop_node - function that deletes the head node
  * @head: pointer to head
  * @line_number: line number in the file with Monty bytecode
  * Return: none
 */
void pop_node(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (!head || !*head)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		globals.retval = -1;
		return;
	}
	temp = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(temp);
	globals.retval = 0;
}
