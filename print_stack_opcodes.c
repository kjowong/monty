#include "monty.h"
/**
 * pall - function that prints all the elements of a list
 * @h: pointer to the constant stack_t head
 * @line_num: line number in the file with Monty bye code
 * Return: none
 */
void pall(stack_t **h, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	temp = *h;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	globals.retval = 0;
}

/**
 * pint - prints all the values of a list
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 * Return: none
 */
void pint(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		globals.retval = -1;
		return;
	}
	else
		printf("%d\n", (*h)->n);
	globals.retval = 0;
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

/**
 * print_rev - function that prints all the elements of a list in reverse
 * @h: pointer to the constant stack_t head
 * @line_num: line number in the file
 * Return: none
 */
void print_rev(stack_t **h, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	temp = *h;

	if (h == NULL || *h == NULL)
	{
		return;
	}
	while (temp != NULL)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
