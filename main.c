#include "monty.h"
int retval = 0;
/**
 * main - entry point for Monty project
 * @ac: number of arguments
 * @av: array of pointers to those arguments
 * Return: Always 0 on success
 */
int main(int ac, char **av)
{
	unsigned int line_number = 0;
	size_t line_len = 0;
	FILE *fp;
	char *line, **tokens;
	stack_t *list_head;
	int len = 0;

	line = NULL;
	list_head = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((len = getline(&line, &line_len, fp)) != -1)
	{
		if (line[0] == '\n' || is_empty(line))
		{
			line_number++;
			continue;
		}
		line_number++;
		tokens = tokenize(line, line_number); /* tokenize line */
		if (tokens == NULL)
		{
			retval = -1;
			break;
		}
		retval = find_opcode(tokens, line_number, &list_head);
		if (retval == -1)
		{
			free_array(tokens);
			break;
		}
		free_array(tokens);
	}
	free(line);
	free_list(list_head);
	fclose(fp);
	if (retval == -1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
