#include "monty.h"
/**
  * last_to_first_rotr - rotates the stack to the bottom, The last element
  * of the stack becomes the top element of the stack
  * @h: pointer to a pointer
  * @ln: line number in the file with Monty bytecode
  * Return: none
 */
void last_to_first_rotr(stack_t **h, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (!h || !(*h) || (list_len(*h) < 2))
		return;
	temp = *h;
	while (1)
	{
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}
	temp->next = *h;
	temp->prev->next = NULL;
	temp->prev = NULL;
	*h = temp;
	temp->next->prev = temp;
	globals.retval = 0;
}
