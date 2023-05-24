#include "ownshell.c"
#include <unistd.h>

/**
 * _myexit - exits the shell
 * @info: contains potential arguments used to maintain
 * constant function prototype
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitchoice;

	if (info->argv[1])  /* If there is an exit argument */
	{
		exitchoice = _erratoi(info->argv[1]);
		if (exitchoice == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: contains potential argument to maintain constant function prototype
 * Return: Always 0 (Success)
 */
int _mycd(info_t *info)
{
	char *h, *directory, buffer[1024];

	int chdir _ret;

	h = getcwd(buffer, 1024);
	if (!h)
		_eputs("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		directory = _getenv(info, "HOME=");
		if (!directory)
			chdir_ret = /* TODO: what should this be? */
				chdir((directory = _getenv(info, "PWD=")) ? directory : "/");
		else
			chdir_ret = chdir(directory);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(h);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((directory = _getenv(info, "OLDPWD=")) ? directory : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "denied info ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	} return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: contains potential argument to maintain constant function prototype
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_eputs("help calls are working. Functions are not implemented yet \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

