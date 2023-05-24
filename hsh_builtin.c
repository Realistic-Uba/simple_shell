#include "shell.h"

/**
 * _myexit - This breaks the shell
 * @info: holds the structure holding the arguments that might be used.
 *          Used to keep up prototype constant function
 *  Return: With the specified exit status, this exits
 *         0 if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int checkdeparture;

	if (info->argv[1])  /* Verify if there is a departure dispute */
	{
		checkdeparture = _erratoi(info->argv[1]);
		if (checkdeparture == -1)
		{
			info->status = 2;
			print_error(info, "Incorrect number entered: ");
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
 * _mycd - This modifies the process's current directory
 * @info: Symbolize the structure holding the arguments. used to keep up
 *          prototype constant function
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int let_cdir;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failed at this point<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			let_cdir = /* TODO: What ought to this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			let_cdir = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		let_cdir = /* TODO: what ought to this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		let_cdir = chdir(info->argv[1]);
	if (let_cdir == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - This modifies the process's current directory
 * @info: Symbolize the structure holding the arguments. used to keep up
 *          prototype constant function
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Calling for assistance is effective. not yet implemented function\n");
	if (0)
		_puts(*arg_array); /* att_unused temporary workaround */
	return (0);
}
