#include "monty.h"
/**
  * pop_node_opcode - function that deletes the head node & returns its data
  * @head: pointer to a pointer
  * @line_number: line number in the file with Monty bytecode
  * Return: the head of the list
 */
stack_t *pop_node_opcode(stack_t **head, size_t line_number)
{
	int n;
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE)
	}
	temp = *head;
	*head = temp->next;
	free(temp);
	return (*head);
}
