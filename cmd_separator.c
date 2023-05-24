#include "shell.h"

/**
 * attach_apex - adds an apex to the list's beginning
 * @top: address of pointer to top apex
 * @cord: cord field of the apex
 * @val: apex lead used by old_info
 *
 * Return: size of list
 */
list_num *attach_apex(list_num **top, const char *cord, int val)
{
	list_num *latest_top;

	if (!top)
		return (NULL);
	latest_top = malloc(sizeof(list_num));
	if (!latest_top)
		return (NULL);
	_memset((void *)latest_top, 0, sizeof(list_num));
	latest_top->val = val;
	if (cord)
	{
		latest_top->cord = _cordstrng(cord);
		if (!latest_top->cord)
		{
			free(latest_top);
			return (NULL);
		}
	}
	latest_top->adjacent = *top;
	*top = latest_top;
	return (latest_top);
}

/**
 * attach_lastapex - adds a node to the list's end
 * @top: address of pointer to top apex
 * @cord: cord field of an apex
 * @val: node lead used by old_info
 *
 * Return: size of list
 */
list_num *attach_lastapex(list_num **top, const char *cord, int val)
{
	list_num *latest_apex, *apex;

	if (!top)
		return (NULL);

	apex = *top;
	latest_apex = malloc(sizeof(list_num));
	if (!latest_apex)
		return (NULL);
	_memset((void *)latest_apex, 0, sizeof(list_num));
	latest_apex->val = val;
	if (cord)
	{
		latest_apex->cord = _cordstrng(cord);
		if (!latest_apex->cord)
		{
			free(latest_apex);
			return (NULL);
		}
	}
	if (apex)
	{
		while (apex->adjacent)
			apex = apex->adjacent;
		apex->adjacent = latest_apex;
	}
	else
		*top = latest_apex;
	return (latest_apex);
}

/**
 * pull_list - Only the str element of a list_num linked list is printed.
 * @hash: pointer to first apex
 *
 * Return: size of list
 */
size_num pull_list(const list_num *hash)
{
	size_num val1 = 0;

	while (hash)
	{
		_place(hash->cord ? hash->cord : "(nill)");
		_place("\n");
		hash = hash->adjacent;
		val1++;
	}
	return (val1);
}

/**
 * erase_apex - erases apex at given apex
 * @top: address of pointer to first apex
 * @lead: lead of apex to erase
 *
 * Return: 1 on success, 0 on failure
 */
int erase_apex(list_num **top, unsigned int apex)
{
	list_num *apex, *last_apex;
	unsigned int val1 = 0;

	if (!top || !*top)
		return (0);

	if (!apex)
	{
		apex = *top;
		*top = (*top)->adjacent;
		free(apex->cord);
		free(apex);
		return (1);
	}
	apex = *top;
	while (apex)
	{
		if (val1 == lead)
		{
			last_apex->adjacent = apex->adjacent;
			free(apex->cord);
			free(apex);
			return (1);
		}
		val1++;
		last_apex = apex;
		apex = apex->adjacent;
	}
	return (0);
}

/**
 * lib_list - frees all apex of a list
 * @top_pointa: address of pointer to top apex
 *
 * Return: void
 */
void lib_list(list_num **top_pointa)
{
	list_num *apex, *adjacent_apex, *top;

	if (!top_pointa || !*top_pointa)
		return;
	top = *top_pointa;
	apex = top;
	while (apex)
	{
		adjacent_apex = apex->adjacent;
		free(apex->cord);
		free(apex);
		apex = adjacent_apex;
	}
	*top_pointa = NULL;
}

