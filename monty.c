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

/**
 * parse_line - this parses a line for an opcode and arguments
 * @line: line to be parsed
 * @stack: a pointer to the head of the stack
 * @line_number: this is the current line number
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *arg, *op_code, *push;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_global.push_arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}

/**
 * read_file - this reads a bytecode file and runs commands
 * @filename: a pathname to file
 * @stack: a pointer to the top of the stack
 */
void read_file(char *filename, stack_t **stack)
{
	char *line;
	size_t j = 0;
	int line_count = 1;
	instruct_func s;
	int check;
	int read;


	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &j, var_global.file)) != -1)
	{
		line = parse_line(var_global.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, line_count);
		line_count++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}

/**
 * get_op_func -  this checks opcode and returns the correct function
 * @str: the opcode
 * Return: this returns a functions, or NULL on failure
 */
instruct_func get_op_func(char *str)
{
	int j;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL},
	};

	j = 0;
	while (instruct[j].f != NULL && strcmp(instruct[j].opcode, str) != 0)
	{
		j++;
	}

	return (instruct[j].f);
}
