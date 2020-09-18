#include "monty.h"

/**
 * get_op - Determine which opcode function to execute
 * @st: The stack
 * @s: The string containing the opcode
 * @lnum: The line number
 *
 * Return: The name of the function to execute
 */
void (*get_op(stack_t **st, char *s, int lnum))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strncmp(ops[i].opcode, s, strlen(ops[i].opcode)) == 0)
			return (ops[i].f);
		i++;
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lnum, s);
	clean(st);
	exit(EXIT_FAILURE);
}