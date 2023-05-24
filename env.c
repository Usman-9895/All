#include "ownshell.h"
#include <unistd.h>

/**
* _myenv - prints the current environment
* @info:  contains potential argument to maintain constant function prototype
* Return: Always 0
*/
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
* _getenv - gets the value of an environment variable
* @info: Structure containing potential arguments. Used to maintain
* @name: env var name
* Return: the value
*/
char *_getenv(info_t *info, const char *name)
{
	list_t *branch = info->env;
	char *a;

	while (branch)
	{
		a = starts_with(branch->str, name);
		if (a && *a)
			return (a);
		branch = branch->next;
	}
	return (NULL);
}

/**
* _mysetenv - Initialize a new environment variable,
* or modify an existing one
* @info: contains potential argument to maintain constant function prototype
* Return: Always 0
*/
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect argument number\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
* _myunsetenv - Remove an environment variable
* @info:  contains potential argument to maintain constant function prototype
* Return: Always 0
*/
int _myunsetenv(info_t *info)
{
	int h;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (h = 1; h <= info->argc; h++)
		_unsetenv(info, info->argv[h]);

	return (0);
}

/**
* populate_env_list - populates env linked list
* @info:  contains potential argument to maintain constant function prototype
* Return: Always 0
*/
int populate_env_list(info_t *info)
{
	list_t *branch = NULL;
	size_t h;

	for (h = 0; environ[h]; h++)
		add_branch_end(&branch, environ[h], 0);
	info->env = branch;
	return (0);
}

