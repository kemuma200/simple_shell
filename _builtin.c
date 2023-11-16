#include "shell.h"

/**
 *_exit - exits the shell
 *@info:structure containing potential arguments
 *Return: 0 if info.argv[0] != "exit"
 */

int _exit(info_t *info)
{
	int exitcheck;


	if (info->argv[1])
	{
		exitcheck = erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_erro(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = erratoi(info->atgv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 *_changedir - changes the current director
 *@info - structure containing potential args
 *Return: 0
 */
int _changedir(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >> getcwd failure msg here <<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
	  	if (!_getenv(info, "OLPWD="))
	  	{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if(chdir_ret == -1)
	{
		print_erro(info, "can't change directory to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 *help - assisting function
 *@info - structure containing potential arguments
 *Return: 0;
 */
int _help(info_t *info)
{
	char ** arg_array;

	arg_array = info->argv;
	_puts("Call on me whenever you need assistance\n");
	if (0)
		_puts(*arg_array);
	return (0);
}
