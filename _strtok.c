#include "header.h"

/**
 * _strtok - function for strtok
 * @str: string to tokenize
 * @delimiters: bases for tokenization
 *
 * Return: token if it is a delimiter, otherwise NULL
 */
char *_strtok(char *str, const char *delimiters)
{
static char *token;
static char *next_token;

char *current;
const char *delimiter;

if (str != NULL)
{
token = str;
next_token = NULL;
}
if (token == NULL)
	return (NULL);

current = token;
delimiter = delimiters;
while (*current != '\0')
{
	while (*delimiter != '\0')
	{
	if (*current == *delimiter)
	{
	*current = '\0';
	next_token = current + 1;
	token = next_token;
	return (token - 1);
	}
	delimiter++;
	}
	delimiter = delimiters;
	current++;
}
token = NULL;
return (token);
}

/**
 * write_message - write message to STDOUT_FILENO
 * @message: the message to write
 *
 * Return: 0 on success, -1 on failure
 */
int write_message(const char *message)
{
ssize_t len = 0;
ssize_t bytes_written = 0;

while (message[len] != '\0')
	len++;

bytes_written = write(STDOUT_FILENO, message, len);
if (bytes_written == -1)
{
	perror("write");
	return (-1);
}
return (0);
}

/**
 * process_command - process a command
 * @command: the command to process
 * @execute: flag indicating whether to execute the command or not
 *
 * Return: 0 on success, -1 on failure
 */
int process_command(const char *command, int execute)
{
char message[100];
char static_part[] = "Executing command: ";
char new_line[] = "\n";

if (execute)
{
_strcpy(message, static_part);
strcat(message, command);
strcat(message, new_line);

if (write_message(message) == -1)
{
	return (-1);
}
}
return (0);
}

/**
 * main1 - entry point
 *
 * Return: 0 on success
 */
int main1(void)
{
char str[] = "ls /var || ls /var";
char delimiters[] = "&&||";
char *token;
int execute = 1;
bool previous_command_success = true;

token = _strtok(str, delimiters);

while (token != NULL)
{
	if (strcmp(token, "&&") == 0)
	{
	if (previous_command_success)
	{
	execute = 1;
	}
	else
	{
	execute = 0;
	}
	}
	else if (strcmp(token, "||") == 0)
	{
	{
	if (!previous_command_success)
	{
	execute = 1;
	}
	else
	{
	execute = 0;
	}
        }
	}
	else if (execute)
	{
	previous_command_success = (system(token) == 0);
	}
	else
	{
	previous_command_success = true;
	}
	token = _strtok(NULL, delimiters);
}
return (0);
}
