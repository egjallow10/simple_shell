#include "shell.h"

/**
  * arg_list - obtains an argument list from the getline
  *
  * @isinteractive: a flag to indicate interactive mode
  * Return: an array of strings that contain the arguments
  */
char **arg_list(int isinteractive)
{
	char **arglist;
	char *buf = NULL;
	int i;
	size_t size_b = 0;

	if (isinteractive)
		print_str("$ ");

	i = getline(&buf, &size_b, stdin);
	if (i == -1)
	{
		if (isinteractive)
			write(STDOUT_FILENO, "\n", 1);
		free(buf);
		return (arglist = strtow("exit", ' '));
	}
	*(buf + i - 1) = '\0';

	arglist = strtow(buf, ' ');
	i = 0;

	free(buf);

	return (arglist);
}

