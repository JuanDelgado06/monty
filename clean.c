#include "monty.h"

/**
 * clean - Free the stack
 * @stack: The stack
 */
void clean(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}