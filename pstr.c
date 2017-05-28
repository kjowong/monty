#include "monty.h"
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
