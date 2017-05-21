#include "monty.h"
/**
  * find_opcode - finds the opcode
  * @head: Pointer to the list
  * @line_number: number of lines in the file
  * Return: -1 on failure
  */
int find_opcode(stack_t **head, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"prev", print_rev},
		{"push", push_node_mode},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop_node},
		{"swap", swap_first_second},
		{"add", add},
		{"nop", nop_node},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
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
	globals.retval = -1;
	return (globals.retval);
}
