#include "monty.h"
/**
  * pop - function that deletes the head node
  * @head: pointer to head
  * @line_number: line number in the file with Monty bytecode
  * Return: none
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (!*head)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		globals.retval = -1;
		return;
	}
	temp = *head;
	if (temp->next)
		temp->next->prev = NULL;
	*head = temp->next;
	free(temp);
	globals.retval = 0;
}

/**
 * swap - swaps the top two elements of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void swap(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	if (list_len(*h) < 2)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		globals.retval = -1;
		return;
	}

	tmp = *h;
	*h = tmp->next;
	tmp->next = (*h)->next;
	(*h)->next = tmp;
	tmp->prev = *h;
	(*h)->prev = NULL;
	if (tmp->next)
		(tmp->next)->prev = tmp;
	globals.retval = 0;
}

/**
  * nop - a function that does nothing
  * @head: pointer to linked list
  * @line_number: number of lines in file
  */
void nop(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	(void)head;
}

/**
 * rotl - rotates the stack to the top; the top element of the
 * stack becomes the last one, and the second top element of the stack becomes
 *  the first one
 * @h: pointer to a pointer
 * @ln: line number in the file with Monty bytecode
 * Return: none
 */
void rotl(stack_t **h, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (!h || !(*h) || !(*h)->next)
		return;
	temp = *h;
	*h = temp->next;
	while (temp->next)
		temp = temp->next;
	temp->next = (*h)->prev;
	temp->next->next = NULL;
	temp->next->prev = temp;
	(*h)->prev = NULL;
	globals.retval = 0;
}

/**
 * rotr - rotates the stack to the bottom, The last element
 * of the stack becomes the top element of the stack
 * @h: pointer to a pointer
 * @ln: line number in the file with Monty bytecode
 * Return: none
 */
void rotr(stack_t **h, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (!h || !(*h) || !(*h)->next)
		return;
	temp = *h;
	while (temp->next)
		temp = temp->next;
	temp->next = *h;
	temp->prev->next = NULL;
	temp->prev = NULL;
	*h = temp;
	temp->next->prev = temp;
	globals.retval = 0;
}
