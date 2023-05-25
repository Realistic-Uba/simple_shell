#include "shell.h"

/**
 * add_node - it adds a node to the begining of the list
 * @head: stand as the address of pointer to head node
 * @str: the string field of node
 * @num: it is the node index used by history
 *Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - it adds a node to the end of the list
 * @head: stands as the address of pointer to head node
 * @str: this is string field of node
 * @num: this represents node idnex used by history
 *Return: the resulting size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}


/**
 * print_list_str - it basically prints only the string element of
 *                  a list_t linked list
 * @h: first node pointer
 *Return: this is the size of list (h)
 */
size_t print_list_str(const list_t *h)
{
	size_t p = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		p++;
	}
	return (p);
}

/**
 * delete_node_at_index - it deletes the  node at given index
 * @head: address of the first node pointer
 * @index: this is index of node to delete
 * Return: success for 1,  failure for 0
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int n = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (n == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		n++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - it free's all nodes of a list
 * @head_ptr: this is the address of pointer to head node
 *Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
