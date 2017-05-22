#include "monty.h"
/**
 * tokenize - toknizes the line from file
 * @line: pointer to line from file
 * Return: array of pointers where 1st is cmd and 2nd arg
 */
char **tokenize(char *line)
{
	char **tokens;
	int i;
	char *token;
	char *delim = "\n ";

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < 3; i++)
	{
		tokens[i] = NULL;
	}
	token = strtok(line, delim);
	tokens[0] = strdup(token);
	if (tokens[0] == NULL)
	{
		return (NULL);
	}
	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, delim);
		tokens[1] = strdup(token);
		if (tokens[1] == NULL)
		{
			return (NULL);
		}
	}
	return (tokens);
}
/**
 * is_empty - check if line needs t be tokenized
 * @str: pointer to string
 * Return: 1 if it is, 0 if not
 */
int is_empty(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
