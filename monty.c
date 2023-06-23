#include "monty.h"

/**
 * main - this is a driver function for monty program
 * @ac: an int num of arguments
 * @av: an opcode file
 * Return: 0
 */


int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(av[1], &stack);
    /* a recordar liberar memorias */
	free_dlistint(stack);
	return (0);
}
