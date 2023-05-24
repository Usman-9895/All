#include "ownshell.h"
#include <stdio.h>

/**
* _eputs - prints an input string to stderr
* @str: string to be printed
* Return: Nothing
*/
void _eputs(char *str)
{
	if (str != NULL)
		fprintf(stderr, "%s", str);
}

/**
* _eputchar - writes the character on c stderr
* @c: The character to print
* Return: On success 1. -1 on error, and errno is set appropriately.
*/
int _eputchar(char c)
{
	return (fputc(c, stderr));
}

/**
* _putfd - writes the character c to given fd
* @c: character to be printed
* @fd: file descriptor to be written
* Return: On success 1, -1 is returned, and errno is set appropriately
*/
int _putfd(char c, int fd)
{
	return (fputc(c, fd));
}

/**
* _putsfd - prints an input string to the specified file descriptor
* @str: string to be printed
* @fd: file descriptor to be written
* Return: number of characters
*/
int _putsfd(char *str, int fd)
{
	if (str != NULL)
		return (fprintf(fd == 2 ? stderr : stdout, "%s", str));
	return (0);
}
