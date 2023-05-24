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
	char *path, *path_copy, *dir;
	unsigned int cmd_len = 0, path_len = 0, dir_len = 0;

	path = _getenv("PATH"), path_len = _strlen(path);
	cmd_len = _strlen(cmd), path_copy = malloc(path_len + 1);
	if (path_copy == NULL)
	{
		free(path);
		return (1);
	}
	_strcpy(path_copy, path);
	dir = strtok(path_copy, ":");
	if (dir == NULL)
		dir = strtok(NULL, ":");
	while (dir != NULL)
	{
		dir_len = _strlen(dir);
		*fullpath = malloc(dir_len + cmd_len + 2);
		if (*fullpath == NULL)
		{
			free(path_copy), free(path);
			return (1);
		}
		_strcpy(*fullpath, dir), (*fullpath)[dir_len] = '/';
		_strcpy(*fullpath + dir_len + 1, cmd);
		(*fullpath)[dir_len + cmd_len + 1] = '\0';
		if (is_executable(*fullpath))
		{
			free(path_copy), free(path);
			return (0);
		}
		else
		{
			free(*fullpath), *fullpath = NULL, dir = strtok(NULL, ":");
		}
	}
	free(path_copy), free(path);
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
