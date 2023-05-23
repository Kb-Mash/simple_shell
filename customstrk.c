#include "header.h"

/**
 * customStrtok - function for strtok
 * @str: string to tokenize
 * @delimiters: bases for tokenization
 *
 * Return: token if it is delimiter otherwise NULL
 */
void customStrtok(const char *str, const char *delimiters)
{
int str_len = strlen(str);
int delim_len = strlen(delimiters);
char token[str_len + 1];
int token_index = 0;
int is_delimiter = 0;

for (int i = 0; i <= str_len; i++)
{
for (int j = 0; j < delim_len; j++)
{
if (str[i] == delimiters[j])
{
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
return;
}
if (write(STDOUT_FILENO, "\n", 1) == -1)
{
perror("write");
return;
}
token_index = 0;
}
else
{
token[token_index++] = str[i];
}
}
}

/**
 * main - entry point
 *
 * Return: void
 */
int main(void)
{
char str[] = "Hello,World,How,Are,You";
char delimiters[] = ",";

customStrtok(str, delimiters);

return (0);
}
