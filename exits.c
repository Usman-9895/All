#include "ownshell.h"
#include <stddef.h>

/**
* _strncpy - copies a string
* @dest: destination to the copied string
* @src: the source string
* @n: the number of characters to be copied
* Return: the concatenated string
*/
char *_strncpy(char *dest, const char *src, int n)
{
	int k;

	for (k = 0; k < n && src[k] != '\0'; k++)
		dest[k] = src[k];

	for (; k < n; k++)
		dest[k] = '\0';

	return (dest);
}

/**
* _strncat - concatenates two strings
* @dest: destination to the first string
* @src: the second string
* @n: the number of bytes to be maximally used
* Return: the concatenated string
*/
char *_strncat(char *dest, const char *src, int n)
{
	int dest_len = 0;
	int k;

	while (dest[dest_len] != '\0')
		dest_len++;

	for (k = 0; k < n && src[k] != '\0'; k++)
		dest[dest_len + k] = src[k];

	dest[dest_len + k] = '\0';

	return (dest);
}

/**
* _strchr - locates a character in a string
* @s: the string to be parsed
* @c: the character to look for
* Return: (s) a pointer to the memory area s
*/
char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}

	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
