#include "shell.h"

/**
 * list_len - it basically determines the length of linked list
 * @h: first node pointer
 * Return: the size of list
 */
size_t list_len(const list_t *h)
{
	size_t p = 0;

	while (h)
	{
		h = h->next;
		p++;
	}
	return (p);
}

/**
 * list_to_strings - it returns an array of strings of the list -> string
 * @head: first node pointer
 * Return: an array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t y = list_len(head), h;
	char **strs;
	char *str;

	if (!head || !y)
		return (NULL);
	strs = malloc(sizeof(char *) * (y + 1));
	if (!strs)
		return (NULL);
	for (y = 0; node; node = node->next, y++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (h = 0; h < y; h++)
				free(strs[h]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[y] = str;
	}
	strs[y] = NULL;
	return (strs);
}


/**
 * print_list - it displays all elements of a list_t linked list
 * @h: first node pointer
 *Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t d = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		d++;
	}
	return (d);
}


/**
 * node_starts_with - it will make returns to the node whose string
 *                    starts with prefix
 * @node: this pointer to list head
 * @prefix: string to be matched
 * @c: this the next character after prefix to match
 * Return: this will return matched node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *ptr = NULL;

	while (node)
	{
		ptr = begins_with(node->str, prefix);
		if (ptr && ((c == -1) || (*ptr == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - this gets the node index
 * @head: this is pointer to list head
 * @node: this is pointer to the node
 *Return: the index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t v = 0;

	while (head)
	{
		if (head == node)
			return (v);
		head = head->next;
		v++;
	}
	return (-1);
}
