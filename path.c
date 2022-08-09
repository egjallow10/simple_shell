#include "shell.h"

/**
  * build_path - Adds each path directory to a NULL-terminated array
  *
  * @path: colon separated string of all paths
  * Return: NULL-terminated array of dir strings
  */
char **build_path(char *path)
{
	char **pathlist;
	int i = 0;

	if (!path)
		return (NULL);

	pathlist = strtow(path, ':');

	if (pathlist)
		return (pathlist);
	pathlist = malloc(sizeof(char **));
	if (!pathlist)
		return (NULL);
	pathlist[i] = malloc(sizeof(char) * 2);
	if (!pathlist[i])
	{
		free(pathlist);
		return (NULL);
	}
	pathlist[i][i] = '.';
	pathlist[i][1] = '\0';
	return (pathlist);
}

/**
  * print_dir - prints the directory of the path found,
  *
  * @path: colon separated string of all paths
  * Return: void
  */
void print_dir(char *path)
{
	if (!path)
		return;

	while (*path)
	{
		if (*path != ':')
			write(STDOUT_FILENO, path, 1);
		else
			write(STDOUT_FILENO, "\n", 1);
		path++;
	}
}

/**
  * print_env - prints the environment variables
  *
  * @env: pointer to array of environment variables
  * Return: void
  */
void print_env(char **env)
{
	int i = 0, k = 0;

	if (!env)
		return;

	while (env[i])
	{
		for (k = 0; env[i][k];)
			k++;
		write(STDOUT_FILENO, env[i], k);
		print_str("\n");
		i++;
	}
}
