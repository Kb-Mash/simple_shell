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
		av[i++] = strdup(token);
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
 * child_process - creates a process to executes a command
 * @path: full path
 * @av: array of full path and its arguments
 * @line: input string
 */
void child_process(char *path, char *av[], char *line)
{
	pid_t pid;
	int status;
	char **env = environ;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(line);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(path, av, env) == -1)
		{
			perror(path);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
