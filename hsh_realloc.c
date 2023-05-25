#include "shell.h"

/**
 * _memset - This function fills a block of memory with a constant byte.
 * @s: Pointer to the memory area.
 * @b: Byte to fill the memory with.
 * @n: Number of bytes to be filled.
 * Return: Pointer to the memory area 's'.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int f;

	for (f = 0; f < n; f++)
		s[f] = b;
	return (s);
}

/**
 * ffree - This function frees up memory allocated for a string of strings.
 * @pp: The string of strings.
 */
void ffree(char **pp)
{
	char **q = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(q);
}

/**
 * _realloc - This function reallocates a block of memory.
 * @ptr: Pointer to the previously allocated block.
 * @old_size: Byte size of the previous block.
 * @new_size: Byte size of the new block.
 * Return: Pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *l;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	l = malloc(new_size);
	if (!l)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		l[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (l);
}
