#include "header.h"

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 *
 * Return: value of environment variable if found, otherwise NULL.
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *delim, *var, *name_value, *value;

	delim = "=";

	if (name != NULL)
	{
	if (environ == NULL)
		return (NULL);
	name_value = strdup(environ[i]);
	while (name_value != NULL)
	{
	var = strtok(name_value, delim);
	if (strcmp(var, name) == 0)
	{
	var = strtok(NULL, delim);
	value = strdup(var);
	free(name_value);
	return (value);
	}
	i++;
	free(name_value);
	name_value = strdup(environ[i]);
	}
	}
	return (NULL);
}
