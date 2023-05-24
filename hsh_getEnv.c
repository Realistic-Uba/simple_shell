#include "shell.h"

/**
 * get_environ - it typically returns the string array replicate of our environ
 * @info: this represents the Structure containing potential arguments.
 *          Used to maintain the prototype constant function
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: the structure that contains potential arguments. Used to maintain
 *        prototype constant function
 *  Return: delete indicates 1, otherwise 0
 * @var: this is for the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t o = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), o);
			o = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		o++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment var,
 *             or change an existing one
 * @info: this is for the structure containing potential arguments.
 *        Used to maintain the prototype constant function
 * @var: this is for the string env var property
 * @value: this if for the string env var value
 * Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *i;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		i = starts_with(node->str, var);
		if (i && *i == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

