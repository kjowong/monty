#include "monty.h"
/**
  * find_opcode - finds the opcode
  * @line_number: number of lines in the file
  * @head: Pointer to the list
  * Return: -1 on failure
  */
int find_opcode(stack_t **head, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push_node_mode},
		{"pall", print_all_pall},
		{"pint", print_first_pint},
		{"pop", pop_node},
		{"swap", swap_first_second},
		{"add", add_first_second},
		{"nop", nop_node},
		{"div", div_first_second},
		{NULL, NULL}
	};

	int i;

	i = 0;
	while (opcodes[i].opcode != NULL)
	{
		if (strncmp(globals.command, opcodes[i].opcode,
			    strlen(globals.command)) == 0)
		{
			opcodes[i].f(head, line_number);
			return (globals.retval);
		}
		i++;
	}
	printf("L%u: unknown instruction %s\n", line_number, globals.command);
	return (-1);
}
