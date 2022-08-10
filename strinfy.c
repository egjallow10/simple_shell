#include "shell.h"

/**
  * _strcat_dir - concatenates two strings with a slash for directories
  *
  * @dest: first string
  * @src: second string
  * Return: dest which will have concatenated string
  */
char *_strcat_dir(char *dest, char *src)
{
	char *cat;
	int i, k = 0;

	cat = malloc(sizeof(char) * (_strlen(dest) + _strlen(src) + 2));
	if (!cat)
		return (NULL);

	for (i = 0; i < _strlen(dest); i++)
		*(cat + k++) = *(dest + i);

	*(cat + k++) = '/';

	for (i = 0; i < _strlen(src); i++)
		*(cat + k++) = *(src + i);

	*(cat + k) = '\0';

	return (cat);
}

/**
  * _malloc - allocates memory for n chars and frees on failure
  *
  * @n: number of chars to allocate memory for
  * @a: 2D array that string will be a part of
  * Return: the pointer to chars
  */
char *_malloc(int n, char **a)
{
	char *ret;

	ret = malloc(sizeof(char) * n);
	if (!ret)
	{
		free_double(a);
		return (NULL);
	}
	return (ret);
}
