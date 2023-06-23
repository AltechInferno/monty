#include "monty.h"

/**
 * isnumber - this checks if a string is a number
 * @str: the string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int j;

	if (str == NULL)
		return (0);
	j = 0;
	while (str[j])
	{
		if (str[0] == '-')
		{
			j++;
			continue;
		}
		if (!isdigit(str[j]))
			return (0);
		j++;
	}
	return (1);
}
