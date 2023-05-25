#include "shell.h"

/**
 * buffer_free - it frees a pointer and 0's the address
 * @ptr: this indicates the address of the pointer to free
 *Return: if freed,1 else 0.
 */
int buffer_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
