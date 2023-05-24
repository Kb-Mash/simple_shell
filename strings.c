#include "header.h"

/**
 * _strcpy - copies the src string to dest pointer
 * @dest: pointer to the buffer to copy to
 * @src: string to be copied
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: string to get length of
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if matching, else non-zero int
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strdup - duplicates a string
 * @s: string to be duplicated
 * Return: pointer to duplicated string
 */
char *_strdup(char *s)
{
	unsigned int k, len;
	char *dup;

	if (s == NULL)
		return (NULL);

	for (len = 0; s[len] != '\0'; len++)
		;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (k = 0; k <= len; k++)
	{
		dup[k] = s[k];
	}
	return (dup);
}

/**
 * _strncmp - compare two strings
 * @s1: first string
 * @s2: second string.
 * @n: number bytes of the strings to compare
 * Return: 0 if s1 and s2 match, else non-zero int
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	for (index = 0; s1[index] && s2[index] && index < n; index++)
	{
		if (s1[index] > s2[index])
			return (s1[index] - s2[index]);
		else if (s1[index] < s2[index])
			return (s1[index] - s2[index]);
	}
	if (index == n)
		return (0);
	else
		return (-15);
}
