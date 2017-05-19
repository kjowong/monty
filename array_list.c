#include "monty.h"
/**
 * free_array - frees a 2D array
 * @array: array to free
 * Return: none
 */
void free_array(char **array)
{
	int i;

	i = 0;
	if (array == NULL || *array == NULL)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
