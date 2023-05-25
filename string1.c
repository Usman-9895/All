#include <stdio.h>
#include <string.h>
#include "ownshell.h"

/**
 * _strcpy - A function that copies a string
 * @dest: the destination of the string
 * @src: the source
 *
 * Return: pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *res;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	res = malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	for (length++; length--;)
		res[length] = *--str;
	return (res);
}

/**
 *_puts - A function that prints an input string
 *@str: the string
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - A function that writes the character c to stdout
 * @c: The character to be printed
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
