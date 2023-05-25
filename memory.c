#include "ownshell.h"

/**
 * bfree - A function that NULLs the address and free the pointers
 * @ptr: pointer address
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
