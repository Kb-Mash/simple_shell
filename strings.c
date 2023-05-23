#include "header.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer for char parameter
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: returns an integer less than, equal to,
 * or greater than zero if s1 is found,re‐spectively,
 * to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strdup - duplicate a string
 * @s: string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(char *s)
{
	unsigned int i, len;
	char *dup_s;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);
	dup_s = malloc(sizeof(char) * (len + 1));
	if (dup_s == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		dup_s[i] = s[i];
	}
	return (dup_s);
}

/**
 * _strcpy - copies a src string to dest string
 * @dest: buffer to copy src string to
 * @src: string to copy
 * Return: pointer to the dest string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
