#include "ownshell.h”

/**
* _myhistory - displays the history list, one command by line, preceded
* with line numbers, starting at 0.
* @info: contains potential argument to maintain constant function prototype
* Return: Always 0
*/
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
* unset_alias - sets alias to string
* @info: the parameter that structs
* @str: string to be used
* Return: Always 0 on success, 1 on error
*/
int unset_alias(info_t *info, char *str)
{
	char *a, b;
	int ret;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*a = b;
	return (ret);
}
/**
* set_alias - sets the alias to the string
* @info: parameter struct
* @str: the string to the allias
* Return: Always 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
	char *a;

	p = _strchr(str, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
* print_alias - prints an alias string
* @branch: the alias node
* Return: Always 0 on success, 1 on error
*/
int print_alias(list_t *branch)
{
	char *p = NULL, *a = NULL;

	if (branch)
	{
		p = _strchr(branch->str, '=');
		for (a = branch->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	} return (1);
}
/**
* _myalias - mimics the alias builtin (man alias)
* @info: Structure with potential arguments
* Return: Always 0
*/
int _myalias(info_t *info)
{
	int i = 0;
	char *a = NULL;
	list_t *branch = NULL;

	if (info->argc == 1)
	{
		branch = info->alias;
		while (branch)
		{
			print_alias(branch);
			branch = branch->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		a = _strchr(info->argv[i], ' = ' );
		if (a)
			set_alias(info, info->argv[i]);
		else
			print_alias(branch_starts_with(info->alias, info->argv[i], ' = ' ));
	}
	return (0);
}
