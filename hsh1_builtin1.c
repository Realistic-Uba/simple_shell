#include "shell.h"

/**
 * _myhistory - shows the history list line by line, one command at a time
 *              line numbers beginning at 0
 * @info: Arrangement with potential arguments. used to keep up
 *        prototype constant function
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - changes alias to a string
 * @info: variable struct
 * @str: the alias string
 *
 * Return: Always 0 for success, 1 on failure
 */
int unset_alias(info_t *info, char *str)
{
	char *ptr, a;
	int let;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	a = *ptr;
	*ptr = 0;
	let = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*ptr = a;
	return (let);
}

/**
 * set_alias - changes alias to a string
 * @info: variable struct
 * @str: the alias string
 *
 * Return: Always 0 for success, 1 on failure
 */
int set_alias(info_t *info, char *str)
{
	char *b;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints a string of aliases
 * @node: alias node
 *
 * Return: Always 0 for success, 1 on failure
 */
int print_alias(list_t *node)
{
	char *ptr = NULL, *b = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (b = node->str; b <= ptr; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - imitates the built-in alias (man alias)
 * @info: Arrangement with potential arguments. used to keep up
 *          prototype constant funtion
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int z = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (z = 1; info->argv[z]; z++)
	{
		ptr = _strchr(info->argv[z], '=');
		if (ptr)
			set_alias(info, info->argv[z]);
		else
			print_alias(node_starts_with(info->alias, info->argv[z], '='));
	}

	return (0);
}
