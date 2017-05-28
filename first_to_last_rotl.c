#include "monty.h"
/**
  * first_to_last_rotl - rotates the stack to the top; the top element of the
  * stack becomes the last one, and the second top element of the stack becomes
  *  the first one
  * @h: pointer to a pointer
  * @ln: line number in the file with Monty bytecode
  * Return: none
 */
void first_to_last_rotl(stack_t **h, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (!(*h) || !(*h) || (list_len(*h) < 2))
		return;
	temp = *h;
	*h = temp->next;
	while (1)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}
	temp->next = (*h)->prev;
	temp->next->next = NULL;
	temp->next->prev = temp;
	(*h)->prev = NULL;
	globals.retval = 0;
}
