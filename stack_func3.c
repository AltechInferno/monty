#include "monty.h"

/**
 * _rotl - a mod top of stack y second top stack
 * @stack: a pointer to lists for monty stack
 * @line_number: a number of line opcode occurs on
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;


	int aux0 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	aux0 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = aux0;
}

/**
 * _rotr - a mod top of stack y second top stacks
 * @stack: a pointer to lists for monty stack
 * @line_number: a number of line opcode occurs on
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	int aux0 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	aux0 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux0;
}

/**
 * _pstr - a mod top of stack y second top stack
 * @stack: a pointer to lists for monty stack
 * @line_number: a number of line opcode occurs on
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;


	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || _isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}
