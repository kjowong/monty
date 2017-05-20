#include "monty.h"
/**
  * find_opcode - finds the opcode
  * @token: double pointer token
  * @line_number: number of lines in the file
  * @head: Pointer to the list
  * Return: -1 on failure
  */
int find_opcode(char **token, unsigned int line_number, stack_t **head)
{

	instruction_t opcodes[] = {
		{"pall", print_node_pall},
		{"pint", print_first_pint},
		{"pop", pop_node},
		{"swap", swap_first_second},
		{"add", add_first_second},
		{"nop", nop_node},
		{NULL, NULL}
	};

	int i;

	if (!token)
		return (-1);
	i = 0;
	if (strcmp(token[0], "push") == 0)
	{
		push_node(head, atoi(token[1]));
		return (globals.retval);
	}
	while (opcodes[i].opcode != NULL)
	{
		if (strncmp(token[0], opcodes[i].opcode, strlen(opcodes[i].opcode)) == 0)
		{
			opcodes[i].f(head, line_number);
			return (globals.retval);
		}
		i++;
	}
	printf("L%u: unknown instruction %s\n", line_number, token[0]);
	return (-1);
}
