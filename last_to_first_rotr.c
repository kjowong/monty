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
