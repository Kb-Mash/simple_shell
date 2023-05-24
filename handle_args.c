#include "header.h"

/**
 * parse_command - populates an array with substrings of input string
 * @av: the array to populate
 * @lineptr: the input string
 * @delim: the delimiter string
 */
void parse_command(char *av[], char *lineptr, char *delim)
{
	char *token = NULL;
	unsigned int i = 0;

	token = strtok(lineptr, delim);
	while (token != NULL && i < SIZE - 1)
	{
		av[i++] = _strdup(token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
}

/**
 * free_arr - frees the elements of an array
 * @av: the array
 */
void free_arr(char *av[])
{
	int i = 0;

	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
}

/**
 * itoa - convert an integer to a string
 * @num: number to convert
 * @buffer: to store the string
 */
void itoa(int num, char *buffer)
{
	int i = 0, j, is_negative = 0;
	char temp;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	do {
		buffer[i++] = num % 10 + '0';
		num /= 10;
	} while (num);

	if (is_negative)
		buffer[i++] = '-';

	for (j = 0; j < i / 2; j++)
	{
		temp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = temp;
	}
	buffer[i] = '\0';
}

/**
 * _error - error message for child process when execve = -1
 * @program: the program's name
 * @av: th array of the command line and its arguments
 * @runs: the number of executions the program has done
 * Return: 127(exit status)
 */
int _error(char *program, char *av[], int runs)
{
	char buffer[50];

	itoa(runs, buffer);

	write(STDERR_FILENO, program, _strlen(program));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buffer, _strlen(buffer));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	return (127);
}

/**
 * child_process - creates a process to executes a command
 * @program: program's name
 * @runs: number of the executions the program has done
 * @path: full path
 * @av: array of full path and its arguments
 * @line: input string
 */
void child_process(char *program, int runs, char *path, char *av[], char *line)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(line);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(path, av, environ) == -1)
		{
			free(line);
			exit(_error(program, av, runs));
		}
	}
	else
		wait(&status);
}
