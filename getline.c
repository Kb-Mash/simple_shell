#include "header.h"

/**
 * *_memcpy - copies memory area
 * @dest: pointer to the memory area to copy @src into
 * @src: source buffer to copy characters from
 * @n: the number of bytes to copy from @src
 * Return: pointer to the destination buffer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
 * _realloc - resizes a string
 * @old_buffer: the string we want to resize
 * @new_size: the new size
 * Return: pointer to the resized buffer for the string
 */
char *_realloc(char *old_buffer, size_t new_size)
{
	char *new_buffer;
	size_t old_size = 0, size = 0;

	if (old_buffer == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(old_buffer);
		return (NULL);
	}
	new_buffer = malloc(new_size);
	if (new_buffer != NULL)
	{
		old_size = _strlen(old_buffer) + 1;
		size = (old_size < new_size) ? old_size : new_size;
		new_buffer = _memcpy(new_buffer, old_buffer, size);
	}
	free(old_buffer);

	return (new_buffer);
}

/**
 * _getline - reads characters from stdin and stores them in a buffer
 * @lineptr: the buffer to store the characters
 * @n: bytes to read
 * @stream: the file stream
 * Return: number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t line;
	char cha = 0, *buffer = NULL;

	if (lineptr == NULL || n == NULL)
		return (-1);
	free(*lineptr);
	if (*n == 0)
		*n = SIZE;
	buffer = malloc(SIZE);
	if (buffer == NULL)
		return (-1);
	for (line = 0; cha != EOF && cha != '\n'; line++)
	{
		if ((read(fileno(stream), &cha, 1)) == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (cha == '#')
		{
			while (cha != '\n' && cha != EOF)
			{
				if ((read(fileno(stream), &cha, 1)) == 0)
				{
					free(buffer);
					exit(EXIT_SUCCESS);
				}
			}
			break;
		}
		buffer[line] = cha;
		if (line >= *n)
		{
			*n *= 2, buffer = _realloc(buffer, *n);
			if (buffer == NULL)
				return (-1);
		}
	}
	buffer[line] = '\0', *lineptr = buffer;
	return (line);
}
