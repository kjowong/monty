#include "monty.h"
/**
 * tokenize - toknizes the line from file
 * @line: pointer to line from file
 * Return: none
 */
void tokenize(char *line)
{
	char *delim = "\t\n ";

	globals.command = strtok(line, delim);
	globals.push_val = strtok(NULL, delim);
}
/**
 * is_empty - checks if line needs to be tokenized
 * @str: pointer to string
 * Return: 1 if it is, 0 if not
 */
int is_empty(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}
/**
 * is_int - checks if string contains all digits
 * @str: pointer to string
 * Return: 1 if it is, 0 if not
 */
int is_int(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			continue;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

/**
 * list_len - returns the number of elements in a list
 * @h: head pointer
 * Return: the number of elements
 */
size_t list_len(stack_t *h)
{
	stack_t *tmp;
	size_t count;

	tmp = h;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
/**
 * free_list - frees a list
 * @head: linked list to free
 * Return: none
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (1)
	{
		if (head == NULL)
			break;
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
}
