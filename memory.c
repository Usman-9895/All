#include "ownshell.h"

/**
 * bfree - function that make pointer and NULL free
 * @ptr: address that make pointer free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}



