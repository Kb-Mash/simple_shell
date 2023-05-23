#include "header.h"

/**
 * _getline - assigns the line
 * @lineptr: to store the input
 * @n: size of line
 * @stream: size of buffer
 * Return: 1 (success), 0 (otherwise)
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t line = 0, r;
	int cha = 0;

if (lineptr == NULL || n == NULL)
	return (-1);
if (*n == 0)
	*n = SIZE;
if (*lineptr == NULL)
{
*lineptr = malloc(*n);
if (*lineptr == NULL)
	return (-1);
}
while (cha != EOF && cha != '\n')
{
r = read(fileno(stream), &cha, 1);
if (r == 0)
{
free(*lineptr);
return (-1);
}
(*lineptr)[line++] = cha;
if (line >= *n)
{
	*n *= 2;
	*lineptr = realloc(*lineptr, *n);
	if (*lineptr == NULL)
		return (-1)
}
}
(*lineptr)[line] = '\0';
return (line);
}
