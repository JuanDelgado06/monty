#include "monty.h"

/**
 * _pall - Print the values on the stack
 * @stack: The stack
 * @line_number: The line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pos = *stack;

	(void) line_number;

	while (pos)
	{
		printf("%d\n", pos->n);
		pos = pos->next;
	}
}