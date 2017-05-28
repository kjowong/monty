#include "monty.h"
/**
  * pop_node - function that deletes the head node & returns its data
  * @head: pointer to a pointer
  * @line_number: line number in the file with Monty bytecode
  * Return: none
 */
void pop_node(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (head == NULL || *head == NULL || list_len(*head) < 1)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		globals.retval = -1;
		return;
	}
	temp = *head;
	*head = temp->next;
	if (*head)
		(*head)->prev = NULL;
	free(temp);
	globals.retval = 0;
}
