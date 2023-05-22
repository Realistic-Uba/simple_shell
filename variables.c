#include "shell.h"

/**
 * liberated - NULLs the address and frees a pointer
 * @locate: address to free the pointer
 *
 * Return: 1 if liberated, otherwise 0.
 */
int liberated(void **locate)
{
	if (locate && *locate)
	{
		freedom(*locate);
		*locate = NULL;
		return (1);
	}
	return (0);
}
