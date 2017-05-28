#include "monty.h"
/**
  * stack - sets the format of the data to a stack (LIFO)
  * This is the default behavior of the program.
  * @head: pointer to linked list
  * @line_number: number of lines in file
  */
void stack(__attribute__((unused)) stack_t **head,
	   __attribute__((unused)) unsigned int line_number)
{
	if (globals.mode == 0)
		return;
	globals.mode = 0;
}
/**
 * queue - sets the format of the data to a queue (FIFO)
 * @head: pointer to linked list
 * @line_number: number of lines in file
 */
void queue(__attribute__((unused)) stack_t **head,
	   __attribute__((unused)) unsigned int line_number)
{
	if (globals.mode == 1)
		return;
	globals.mode = 1;
}
