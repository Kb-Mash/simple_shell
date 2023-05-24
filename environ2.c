#include "header.h"

/**
 * unset_env - Helper function to unset an environment variable
 * @variable: Name of the environment variable
 *
 * Return: 0 on success, -1 on failure
 */
int unset_env(const char *variable)
{
	int i;
	size_t var_len;

	if (variable == NULL)
	{
	write(STDERR_FILENO, "unsetenv: Invalid argument\n", 27);
	return (-1);
	}
	var_len = strlen(variable);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], variable, var_len) == 0 &&
				environ[i][var_len] == '=')
		{
		for (; environ[i] != NULL; i++)
		{
		environ[i] = environ[i + 1];
		}
		return (0);
		}
	}
write(STDERR_FILENO, "unsetenv: Variable not found\n", 29);
return (-1);
}
