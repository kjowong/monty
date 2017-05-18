#include "monty.h"
/**
  * pop_node_opcode - function that deletes the head node & returns its data
  * @head: pointer to a pointer
  * @line_number: line number in the file with Monty bytecode
  * Return: 0 on success, -1 on failure
 */
int pop_node(stack_t **head, size_t line_number)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		printf("L%lu: can't pop an empty stack\n", line_number);
		return (-1);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
	return (0);
}
