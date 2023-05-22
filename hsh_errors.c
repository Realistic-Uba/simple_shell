#include "shell.h"

/**
 *_eputs - This displays the input string.
 * @str: to be printed string
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int r = 0;

	if (!str)
		return;
	while (str[r] != '\0')
	{
		_eputchar(str[r]);
		r++;
	}
}

/**
 * _eputchar - This sends the character c to the standard error
 * @c: to print a character
 *
 * Return: 1 on success.
 * Errno is set appropriately and -1 is returned in the event of an error
 */
int _eputchar(char c)
{
	static int p;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || p >= WRITE_BUF_SIZE)
	{
		write(2, buf, p);
		p = 0;
	}
	if (c != BUF_FLUSH)
		buf[p++] = c;
	return (1);
}

/**
 * _putfd - This writes the character c to the provide fd
 * @c: The character to be printed
 * @fd: to write to filedescriptor
 *
 * Return: 1 foe success.
 * In the event of an error, -1 is returned and errno is suitably set.
 */
int _putfd(char c, int fd)
{
	static int p;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || p >= WRITE_BUF_SIZE)
	{
		write(fd, buf, p);
		p = 0;
	}
	if (c != BUF_FLUSH)
		buf[p++] = c;
	return (1);
}

/**
 *_putsfd - This outputs an input string.
 * @str: to be printed string
 * @fd: to write to file descriptor
 *
 * Return: chars put number
 */
int _putsfd(char *str, int fd)
{
	int p = 0;

	if (!str)
		return (0);
	while (*str)
	{
		p += _putfd(*str++, fd);
	}
	return (p);
}
