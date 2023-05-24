#ifndef HEADER_H
#define HEADER_H

/*libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdbool.h>

#define SIZE 1024

extern char **environ;

/*function prototypes*/
void parse_command(char *av[], char *lineptr, char *delim);
void free_arr(char *av[]);
int is_executable(char *cmd);
int search_path(char *cmd, char **fullpath);
int full_path(char *cmd, char **fullpath);
void itoa(int num, char *buffer);
int _error(char *program, char *av[], int runs);
void child_process(char *program, int runs,
char *path, char *av[], char *line);
char *_getenv(char *name);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delimiters);
int write_message(const char *message);
int process_command(const char *command, int execute);
int main1(void);


char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif
