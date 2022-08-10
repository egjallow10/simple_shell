#include "shell.h"
/**
  * check_path - checks if path with command exists
  *
  * @str: string to add to path
  * Return: the path if valid, NULL otherwise
  */
char *check_path(char *str)
{
	char **pathlist = NULL;
	char *full_cmd = NULL;
	int i;

	pathlist = build_path(_getenv("PATH"));

	for (i = 0; pathlist[i]; i++)
	{
		full_cmd = _strcat_dir(pathlist[i], str);
		if (access(full_cmd, F_OK))
			free(full_cmd);
		else
			break;
	}
	if (!pathlist[i])
	{
		free_double(pathlist);
		return (str);
	}
	if (pathlist)
		free_double(pathlist);
	return (full_cmd);
}
