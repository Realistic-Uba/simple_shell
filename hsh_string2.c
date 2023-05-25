#include "shell.h"

/**
 * _strcpy - this copies a string
 * @dest: this is the destination
 * @src: this is the source
 *
 * Return: a pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int m = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[m])
	{
		dest[m] = src[m];
		m++;
	}
	dest[m] = 0;
	return (dest);
}

/**
 * _strdup - this replicates a string
 * @str: this is the string to replicate
 *
 * Return: a pointer to the replicated string
 */
char *_strdup(const char *str)
{
	int lgt = 0;
	char *tur;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lgt++;
	tur = malloc(sizeof(char) * (lgt + 1));
	if (!tur)
		return (NULL);
	for (lgt++; lgt--;)
		tur[lgt] = *--str;
	return (tur);
}

/**
 *_puts - this basically prints an input string
 *@str: this is the string to be printed
 *
 * Return: NULL
 */
void _puts(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_putchar(str[b]);
		b++;
	}
}

/**
 * _putchar - this function to write the character c to stdout
 * @c: this is the character to print
 *
 * Return: 1 on success.
 * if error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int v;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
	{
		write(1, buf, v);
		v = 0;
	}
	if (c != BUF_FLUSH)
		buf[v++] = c;
	return (1);
}
