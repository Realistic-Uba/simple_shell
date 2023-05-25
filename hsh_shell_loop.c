#include "shell.h"

/**
 * hsh - This function represents the main shell loop.
 * @info: Pointer to the info struct for parameters and return values.
 * @av: Argument vector from main().
 * Return: 0 on success, 1 on error, or an error code.
 */
int hsh(info_t *info, char **av)
{
	ssize_t o = 0;
	int builtIn_ret = 0;

	while (o != -1 && builtIn_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		o = get_input(info);
		if (o != -1)
		{
			set_info(info, av);
			builtIn_ret = find_builtin(info);
			if (builtIn_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtIn_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtIn_ret);
}

/**
 * find_builtin - This function finds a builtin command.
 * @info: Pointer to the info struct for parameters and return values.
 * Return: -1 if builtin not found,
 *         0 if builtin executed successfully,
 *         1 if builtin found but not successful,
 *         -2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
	int p, built_In_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (p = 0; builtintbl[p].type; p++)
		if (_strcmp(info->argv[0], builtintbl[p].type) == 0)
		{
			info->line_count++;
			built_In_ret = builtintbl[p].func(info);
			break;
		}
	return (built_In_ret);
}

/**
 * find_cmd - This function finds a command in the PATH.
 * @info: Pointer to the info struct for parameters and return values.
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int n, m;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (n = 0, m = 0; info->arg[n]; n++)
		if (!is_delim(info->arg[n], " \t\n"))
			m++;
	if (!m)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - This function forks an exec thread to run a command.
 * @info: Pointer to the info struct for parameters and return values.
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
