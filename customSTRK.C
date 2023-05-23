#include "header.h"

/**
 * customStrtok - function for strtok
 * @str: string to tokenize
 * @delimiters: bases for tokenization
 *
 * Return: token if it is a delimiter, otherwise NULL
 */
char *customStrtok(const char *str, const char *delimiters)
{
int str_len = strlen(str);
int delim_len = strlen(delimiters);
char token[100];
int token_index = 0;
int is_delimiter = 0;
int i, j;

for (i = 0; i <= str_len; i++)
{
is_delimiter = 0;
for (j = 0; j < delim_len; j++)
{
if (str[i] == delimiters[j]){
is_delimiter = 1;
break;
}
}
if (is_delimiter || str[i] == '\0')
{
token[token_index] = '\0';
if (write(STDOUT_FILENO, token, strlen(token)) == -1)
{
perror("write");
return (NULL);
}
if (write(STDOUT_FILENO, "\n", 1) == -1)
{
perror("write");
return (NULL);
}
return (strdup(token));
}
else
{
token[token_index++] = str[i];
}
}

return (NULL);
}

/**
 * main1 - entry point
 *
 * Return: 0 on success
 */
int main1(void)
{
char str[] = "Hello,World,How,Are,You";
char delimiters[] = ",";
char *token;

token = customStrtok(str, delimiters);
while (token != NULL)
{
free(token);
token = customStrtok(NULL, delimiters);
}

return (0);
}
