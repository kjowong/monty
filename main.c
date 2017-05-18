#include "monty.h"
/**
 * main - entry point for Monty project
 * @ac: number of arguments
 * @av: array of pointers to those arguments
 * Return: Always 0 on success
 */
int main(int ac, char **av)
{
	size_t line_number;
	int retval, line_len;
	FILE *fp;
	char *line, **tokens;
	stack_t *list_head;

	line_number = 0;
	line = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], O_RDONLY);
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((line_len = getline(&line, &line_len, fp)) != -1)
	{
		tokens = strtow(line, ' '); /* tokenize line */
		if (tokens == NULL)
		{
			printf("Error: malloc failed\n");
			retval = -1;
			break;
		}
		retval = find_opcode(tokens, ++line_number, &list_head);
		if (retval == -1)
			break;
	}
	free(line);
	fclose(fp);
	free_list(list_head);
	free_array(tokens);
	if (retval == -1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
