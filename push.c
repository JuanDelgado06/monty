#include "monty.h"

/**
 * _push - Push an element to the stack
 * @stack: The stack
 * @line_number: The line number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (number == -1)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
			line_number);
		clean(stack);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		clean(stack);
		exit(EXIT_FAILURE);
	}

	new->n = number;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}