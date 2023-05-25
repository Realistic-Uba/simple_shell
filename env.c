#include "shell.h"

/**
 * _myenv - this displays the environment currently
 * @info: Symbolize the structure holding the arguments. used to keep up
 *          prototype constant function
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - The value of an environ variable is fetched
 * @info: Symbolize the structure holding the arguments. used to keep up
 *        prototype constant function
 * @name: symbolize  the env var name
 *
 * Return: it's value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *a;

	while (node)
	{
		a = begins_with(node->str, name);
		if (a && *a)
			return (a);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a fresh environment variable using this,
 *             or change a current one
 * @info: Symbolize the structure holding the arguments. used to keep up
 *        prototype constant function.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Inadequate number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Eliminate an environment variable
 * @info: Arrangement with potential arguments. used to keep up
 *        prototype constant function
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int r;

	if (info->argc == 1)
	{
		_eputs("insufficient arguments.\n");
		return (1);
	}
	for (r = 1; r <= info->argc; r++)
		_unsetenv(info, info->argv[r]);

	return (0);
}

/**
 * populate_env_list - It fills the env linked list
 * @info: Arrangement with potential arguments. used to keep up
 *          prototype constant function
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t r;

	for (r = 0; environ[r]; r++)
		add_node_end(&node, environ[r], 0);
	info->env = node;
	return (0);
}
