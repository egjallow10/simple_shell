#include "shell.h"

/**
  * print_str - prints a string to standard out
  *
  * @str: string to be write out
  * Return: int how many chars written
  */
int print_str(char *str)
{
	int i;

	if (!str)
		return (-1);
	for (i = 0; *(str + i);)
		i++;
	return (write(STDOUT_FILENO, str, i));
}
