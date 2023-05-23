#include "header.h"

/**
 * is_executable - checks if a given command is executable
 * @cmd: the command to check
 * Return: 1(success), else 0
 */
int is_executable(char *cmd)
{
	if (access(cmd, X_OK) == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * search_path - searches for the full path of a command
 * @cmd: the command
 * @fullpath: pointer to a string that will store the path
 * Return: 0(success), else 1
 */
int search_path(char *cmd, char **fullpath)
{
	char *path = _getenv("PATH"), *path_copy, *dir;
	unsigned int cmd_len = strlen(cmd), path_len = strlen(path), dir_len = 0;
	path_copy = malloc(path_len + 1);
	
	if (path_copy == NULL)
		return (1);
	strcpy(path_copy, path);

	dir = _strtok(path_copy, ":");
	if (dir == NULL)
		dir = strtok(NULL, ":");
	while (dir != NULL)
	{
		dir_len = strlen(dir);
		*fullpath = malloc(dir_len + cmd_len + 2);
		if (*fullpath == NULL)
		{
			free(path);
			free(path_copy);
			return (1);
		}
		strcpy(*fullpath, dir);
		(*fullpath)[dir_len] = '/';
		strcpy(*fullpath + dir_len + 1, cmd);
		(*fullpath)[dir_len + cmd_len + 1] = '\0';
		if (is_executable(*fullpath))
		{
			free(path);
			free(path_copy);
			return (0);
		}
		else
		{
			free(*fullpath);
			*fullpath = NULL;
			dir = _strtok(NULL, ":");
		}
	}
	free(path);
	free(path_copy);
	return (1);
}

/**
 * full_path - retrieve the full path of a command
 * @cmd: the command
 * @fullpath: the pointer to string that will store path
 * Return: 0(success), else 1
 */
int full_path(char *cmd, char **fullpath)
{
	if (is_executable(cmd))
	{
		*fullpath = _strdup(cmd);
		if (*fullpath == NULL)
		{
			return (1);
		}
		return (0);
	}
	return (search_path(cmd, fullpath));
}
