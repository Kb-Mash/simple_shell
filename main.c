#include "header.h"

/**
 * main - runs a unix line intepreter
 * Return: 0(success)
 */

int main(void)
{
	char *lineptr = NULL, *av[SIZE], *delim = NULL, *fullpath = NULL;
	size_t n = 0;
	int runs = 0, found;

	delim = " \n\t\r";
	while (1)
	{
		++runs;
		write(STDOUT_FILENO, "($) ", strlen("($) "));
		fflush(stdout);
		if (getline(&lineptr, &n, stdin) == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(lineptr);
			break;
		}
		if (strcmp(lineptr, "exit\n") == 0)
		{
			free(lineptr);
			break;
		}
		parse_command(av, lineptr, delim);

		if (av[0] == NULL)
			continue;
		else
		{
			found = full_path(av[0], &fullpath);
			if (found == 0)
				child_process(fullpath, av, lineptr);
			else
				perror(av[0]);
		}
		free_arr(av);
		free(fullpath);
	}
	return (0);
}
