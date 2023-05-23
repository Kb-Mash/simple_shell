#include "header.h"

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 *
 * Return: value of environment variable if found, otherwise NULL.
 */
char *_getenv(char *name)
{
	int i = 0;
	char *delim, *var, *name_value, *value;

	delim = "=";

	if (name != NULL)
	{
	if (environ == NULL)
		return (NULL);
	name_value = _strdup(environ[i]);
	while (name_value != NULL)
	{
	var = strtok(name_value, delim);
	if (_strcmp(var, name) == 0)
	{
	var = strtok(NULL, delim);
	value = _strdup(var);
	free(name_value);
	return (value);
	}
	i++;
	free(name_value);
	name_value = _strdup(environ[i]);
	}
	}
	return (NULL);
}
