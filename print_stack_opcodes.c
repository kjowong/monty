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
 * pchar - prints the char at the top of the stack
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 */
void pchar(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		globals.retval = -1;
		return;
	}
	if ((*h)->n < 32 || (*h)->n > 126)
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		globals.retval = -1;
		return;
	}
	printf("%c\n", (*h)->n);
	globals.retval = 0;
}

/**
 * pstr - prints the string starting at the top of the stack, followed by a
 * new line. The integer stored in each element of the stack is treated as
 * the ascii value of the character to be printed
 * @h: head pointer
 * @line_number: line number in the file with Monty byte code
 */
void pstr(stack_t **h, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (!h || !(*h))
	{
		putchar('\n');
		return;
	}
	tmp = *h;
	while (tmp)
	{
		if ((tmp->n == 0) || (tmp->n < 32) || (tmp->n > 126))
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
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
