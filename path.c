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
