#include "ownshell.h"
#include <stdlib.h>
#include <string.h>

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

int _unsetenv(info_t *info, char *var)
{
	list_t branch = info->env;
	size_t t = 0;

	if (!branch || !var)
		return (0);

	while (branch)
	{
		if (starts_with(branch->str, var) && branch->str[strlen(var)] == '=')
		{
			info->env_changed = delete_branch_at_index(&(info->env), t);
			t = 0;
			branch = info->env;
		}
		else
		{
			branch = branch->next;
			t++;
		}
	}

	return (info->env_changed);
}

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *branch;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(strlen(var) + strlen(value) + 2);
	if (!buf)
		return (1);

	strcpy(buf, var);
	strcat(buf, "=");
	strcat(buf, value);

	node = info->env;
	while (branch)
	{
		p = starts_with(branch->str, var);
		if (p && *p == '=')
		{
			free(branch->str);
			branch->str = buf;
			info->env_changed = 1;
			return (0);
		}
		branch = branch->next;
	}

	add_branch_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
