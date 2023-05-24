#include "header.h"

/**
 * set_env - function to set or modify environment variable
 * @variable: name of environment variable
 * @value: value to set for environment variable
 * @datash: data relevant (environ)
 *
 * Return: 0 on success, -1 on failure
 */
int set_env(const char *variable, const char *value, data_shell *datash)
{
	int i;
	char *new_var;
	size_t var_len, value_len;

if (variable == NULL || value == NULL)
{
	write(STDERR_FILENO, "setenv: Invalid arguments\n", 26);
	return (-1);
}
var_len = strlen(variable);
value_len = strlen(value);
new_var = malloc(var_len + value_len + 2);
if (new_var == NULL)
{
	perror("setenv: Memory allocation failed");
	return (-1);
}
_strcpy(new_var, variable);
strcat(new_var, "=");
strcat(new_var, value);

for (i = 0; datash->_environ[i] != NULL; i++)
{
	if (strncmp(datash->_environ[i], variable, var_len) == 0 &&
			datash->_environ[i][var_len] == '=')
	{
	free(datash->_environ[i]);
	datash->_environ[i] = new_var;
	return (0);
	}
	datash->_environ[i] = new_var;
	datash->_environ[i + 1] = NULL;
	return (0);
}
