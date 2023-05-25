#include "shell.h"

/**
 * it_is_chain - this test if current char in buffer is a chain delimeter
 * @info: this is the parameter struct
 * @buf: this is  the char buffer
 * @p: this is address of current position in buf
 *
 * Return: 1 if chain delimeter, otherwise 0
 */
int it_is_chain(info_t *info, char *buf, size_t *p)
{
	size_t n = *p;

	if (buf[n] == '|' && buf[n + 1] == '|')
	{
		buf[n] = 0;
		n++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[n] == '&' && buf[n + 1] == '&')
	{
		buf[n] = 0;
		n++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[n] == ';') /* found end of this command */
	{
		buf[n] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = n;
	return (1);
}

/**
 * chain_check - it confirms and if checks we should continue chaining
 *               based on last status
 * @info: this is the parameter struct
 * @buf: this is  the char buffer
 * @p: this is the address of current position in buf
 * @i: this is the starting position in buf
 * @len: this is length of buffer
 *
 * Return: Void
 */
void chain_check(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t h = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			h = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			h = len;
		}
	}

	*p = h;
}

/**
 * replace_alias - this replaces an aliases in the tokenized string
 * @info: this is the parameter struct
 *
 * Return: 1 if replaced, otherwise 0
 */
int replace_alias(info_t *info)
{
	int b;
	list_t *node;
	char *ptr;

	for (b = 0; b < 10; b++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		ptr = _strchr(node->str, '=');
		if (!ptr)
			return (0);
		ptr = _strdup(ptr + 1);
		if (!ptr)
			return (0);
		info->argv[0] = ptr;
	}
	return (1);
}

/**
 * replace_vars - this functions to replace vars in the tokenized string
 * @info: this is the parameter struct
 *
 * Return: 1 if replaced, otherwise 0
 */
int replace_vars(info_t *info)
{
	int f = 0;
	list_t *node;

	for (f = 0; info->argv[f]; f++)
	{
		if (info->argv[f][0] != '$' || !info->argv[f][1])
			continue;

		if (!_strcmp(info->argv[f], "$?"))
		{
			replace_string(&(info->argv[f]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[f], "$$"))
		{
			replace_string(&(info->argv[f]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[f][1], '=');
		if (node)
		{
			replace_string(&(info->argv[f]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[f], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - this functions to replace string
 * @old: this is the address of the old string
 * @new: this is the new string
 *
 * Return: 1 if replaced, otherwise 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
