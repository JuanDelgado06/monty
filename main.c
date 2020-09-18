#include "monty.h"

int number = -1;

/**
 * main - program execute
 * @argc: The number of command line arguments
 * @argv: The command line arguments
 *
 * Return: EXIT_SUCCCESS OR EXIT_FAILURE
 */

int main(int argc, char **argv)
{
    FILE *fd;
    char str[1024];
    char * token = NULL, * token2 = NULL;
    unsigned int n_line = 1;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: monty file");
        exit(EXIT_FAILURE);
    }

    fd = fopen(argv[1], "r");
    if (!fd)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
			argv[1]);
		exit(EXIT_FAILURE);
    }

    while (fgets(str, sizeof(str), fd))
	{
		token = strtok(str, " ");
        token2 = strtok(NULL, " ");

        if(token2)
            number = atoi(token2);
        else
            number = -1;
        if(token[0] != '\n')
            get_op(&stack, token, n_line)(&stack, n_line);
        n_line++;
	}

    clean(&stack);
    fclose(fd);
    return (EXIT_SUCCESS);
}