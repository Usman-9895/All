#include "ownshell.h"
#include <stdio.h>
#include <limits.h>

/**
* _erratoi - converts a string to an integer
* @s: string that will be converted
* Return: 0 if no numbers in a string, converted number, if not return -1
*/
int _erratoi(char *s)
{
	int value = 0;
	int sign = 1;
	int i = 0;

	if (*s == '+')
		s++;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}

	for (; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (value > INT_MAX / 10 || (value == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))
				return (-1);

			value = value * 10 + (s[i] - '0');
		}
		else
		{
			return (-1);
		}
	}

	return (value * sign);
}

/**
* print_error - prints an error message
* @info: the parameter and info return
* @estr: string that contains specified error
* Return: void
*/
void print_error(info_t *info, char *estr)
{
	fprintf(stderr, "%s: %d: %s: %s", info->fname, info->line_count, info->argv[0], estr);
}

/**
* print_d - function prints a decimal (integer) number (base 10)
* @input: the input
* @fd: write to the file descriptor
* Return: characters to be printed
*/
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int number = 0;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;

	if (input < 0)
	{
		__putchar('-');
		number++;
		input = -input;
	}

	if (input / 10)
		number += print_d(input / 10, fd);

	__putchar('0' + input % 10);
	number++;

	return (number);
}

/**
* convert_number - converter function
* @num: number
* @base: base
* @flags: argument flags
* Return: string
*/
char *convert_number(long int num, int base, int flags)
{
	static char buffer[50];
	char *ptr;
	unsigned long k = num;
	const char *array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";

	ptr = &buffer[49];
	*ptr = '\0';

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		k = -num;
		*--ptr = '-';
	}

	do {
		*--ptr = array[k % base];
		k /= base;
	} while (k != 0);

	return (ptr);
}

/**
* remove_comments - replaces the first entrance of '#' with '\0'
* @buf: address of the string to modify
* Return: void
*/
void remove_comments(char *buf)
{
	int i = 0;

	while (buf[i] != '\0')
	{
		if (buf[i] == '#' && (i == 0 || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
		i++;
	}
}
