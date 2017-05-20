#include "monty.h"
/**
  * pchar - prints the char at the top of the stack
  * @h: head pointer
  * @line_number: line number in the file with Monty byte code
  */
void pchar(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't pchar, stack empty", line_number);
		globals.retval = -1;
		return;
	}
	if ((*h)->n < 32 || (*h)->n > 126)
	{
		printf("L%u: can't pchar, value out of range", line_number);
		globals.retval = -1;
		return;
	}
	printf("%c\n", (*h)->n);
	globals.retval = 0;
}
