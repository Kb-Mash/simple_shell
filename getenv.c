#include "header.h"

/**
 * _getenv - retrieves an environment variable's value
 * @name: name of the environment variable
 * Return: value of the environment variable
 */
char *_getenv(char *name)
{
	int var_len, val_len, index, position, k;
	char *val;

	var_len = _strlen(name);

	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(name, environ[index], var_len) == 0)
		{
			val_len = _strlen(environ[index]) - var_len;
			val = malloc(sizeof(char) * val_len);
			if (val == NULL)
			{
				free(val);
				return (NULL);
			}

			k = 0;
			for (position = var_len + 1; environ[index][position]; position++, k++)
			{
				val[k] = environ[index][position];
			}
			val[k] = '\0';

			return (val);
		}
	}
	return (NULL);
}
