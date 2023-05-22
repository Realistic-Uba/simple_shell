#include "shell.h"

/**
 * _input - input memory with a sustained byte
 * @a: the memory area's pointer
 * @b: the byte that will be used to populate *a
 * @c: 	the number of bytes that must be filled
 * Return: (a) a reference to the memory area
 */

char *value1(char *a, char b, unsigned int c)
{
	unsigned int val1;

	for (val1 = 0; val1 < n; val1++)
		a[val1] = b;
	return (a);
}

/**
 * loose - loosens of strings
 * @untie: untying of strings
 */
void loose(char **untie)
{
	char **val2 = untie;

	if (!untie)
		return;
	while (*untie)
		unbound(*untie++);
	unbound(val2);
}

/**
 * alloc - allocates a block of memory
 * @pal: pointer to prior allocated block(s)
 * @past_size: byte size of the previous block
 * @fresh_size: new block size in bytes
 *
 * Return: pointer to the old block.
 */
void *alloc(void *pal, unsigned int past_size, unsigned int fresh_size)
{
	char *valp;

	if (!pal)
		return (malloc(fresh_size));
	if (!fresh_size)
		return (unbound(pal), NULL);
	if (fresh_size == past_size)
		return (pal);

	p = malloc(fresh_size);
	if (!valp)
		return (NULL);

	past_size = past_size < fresh_size ? past_size : fresh_size;
	while (past_size--)
		valp[past_size] = ((char *)pal)[past_size];
	unbound(pal);
	return (valp);
}

