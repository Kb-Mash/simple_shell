#include "header.h"

/**
 * main - runs a unix line intepreter
 * @argc: the number of arguments passed into main function
 * @argv: arrray storing the arguments
 * Return: 0(success)
 */
int main(int __attribute__ ((unused)) argc, char **argv)
{
	char *lineptr = NULL, *delim = NULL,  *av[SIZE], *fullpath = NULL;
	size_t n = 0;
	ssize_t line = 0;
	int runs = 0, found;

	delim = " \n\t\r";
	while (1)
	{
		++runs;
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "($) ", _strlen("($) "));
			fflush(stdout);
		}
		line = _getline(&lineptr, &n, stdin);
		if (line == EOF || _strcmp(lineptr, "exit\n") == 0)
		{
			free(lineptr);
			break;
		}

		parse_command(av, lineptr, delim);
		if (av[0] == NULL)
			continue;
		found = full_path(av[0], &fullpath);
		if (found == 0)
			child_process(argv[0], runs, fullpath, av, lineptr);
		else
			_error(argv[0], av, runs);

		free_arr(av);
		free(fullpath);
	}
	return (0);
}
