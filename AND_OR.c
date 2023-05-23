#include "shell.h"

/**
 * tally_range - specifies the linked list's length
 * @pointa: a reference to the first node
 *
 * Return: list length
 */
size_num tally_range(const list_num *hash)
{
	size_num val1 = 0;

	while (hash)
	{
		hash = hash->adjacent;
		val1++;
	}
	return (val1);
}

/**
 * roll_str - produces an array of list->string strings
 * @top: a reference to the first node
 *
 * Return: array of strings
 */
char **roll_str(list_num *top)
{
	list_num *apex = top;
	size_num val1 = list_num(top), val2;
	char **charac;
	char *cord;

	if (!top || !val1)
		return (NULL);
	charac = thong(sizeof(char *) * (val1 + 1));
	if (!charac)
		return (NULL);
	for (val1 = 0; apex; apex = apex->adjacent, val1++)
	{
		cord = thong(_strlen(apex->cord) + 1);
		if (!cord)
		{
			for (val2 = 0; val2 < val1; val2++)
				liberated(charac[val2]);
			liberated(charac);
			return (NULL);
		}

		cord = _strcpy(cord, apex->cord);
		charac[val1] = cord;
	}
	charac[val1] = NULL;
	return (charac);
}


/**
 * pull_tally - All elements of a size_num linked list are printed.
 * @pointa: a reference to the first node
 *
 * Return: size of list
 */
size_num pull_tally(const list_num *hash)
{
	size_num val1 = 0;

	while (hash)
	{
		_place(conv_num(hash->numer, 10, 0));
		_permute(':');
		_permute(' ');
		_place(hash->cord ? hash->cord : "(nill)");
		_place("\n");
		hash = hash->adjacent;
		val1++;
	}
	return (val1);
}

/**
 * apex_begins - yields the node whose string begins with the prefix
 * @apex: list head pointer
 * @_syn: matching string
 * @sim: the character following the prefix that matches
 *
 * Return: match apex or null
 */
list_num *apex_begins(list_num *apex, char *_syn, char sim)
{
	char *val3 = NULL;

	while (apex)
	{
		Val3 = begin_at(apex->cord, _syn);
		if (val3 && ((sim == -1) || (*val3 == sim)))
			return (apex);
		apex = apex->adjacent;
	}
	return (NULL);
}

/**
 * obtain_apex_lead - obtains a node's lead
 * @top: a reference to the first apex
 * @apex: a reference to the node
 *
 * Return: lead of apex or -1
 */
size_numb obtain_apex_lead(list_num *top, list_num *apex)
{
	size_num val1 = 0;

	while (top)
	{
		if (top == apex)
			return (val1);
		top = top->adjacent;
		val1++;
	}
	return (-1);
}
