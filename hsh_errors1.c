#include "shell.h"

/**
 * _erratoi - this changes a string to an integer
 * @s: the string that will be transformed
 * Return: If there are no numbers in the string, return 0;
 *         otherwise, return the converted number
 *       on error -1
 */
int _erratoi(char *s)
{
	int p = 0;
	unsigned long int final = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (p = 0;  s[p] != '\0'; p++)
	{
		if (s[p] >= '0' && s[p] <= '9')
		{
			final *= 10;
			final += (s[p] - '0');
			if (final > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (final);
}

/**
 * print_error - prints a message in error
 * @info: information struct for parameters and returns
 * @estr: string with the indicated error type
 * Return: 0 if the string contains no numbers; else, a converted number
 *        on error -1
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function outputs an integer decimal (base 10) number.
 * @input: this is the input
 * @fd: writing to the filedescriptor
 * Return: the number of characters that are printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int p, countN = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		countN++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (p = 1000000000; p > 1; p /= 10)
	{
		if (_abs_ / p)
		{
			__putchar('0' + current / p);
			countN++;
		}
		current %= p;
	}
	__putchar('0' + current);
	countN++;

	return (countN);
}

/**
 * convert_number - a converter function that clones itoa
 * @num: the number
 * @base: the base
 * @flags:the argument flags
 * Return: the string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long p = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		p = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[p % base];
		p /= base;
	} while (p != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function substitutes "0" for the first occurence of "#"
 * @buf: address of the modified string
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int r;

	for (r = 0; buf[r] != '\0'; r++)
		if (buf[r] == '#' && (!r || buf[r - 1] == ' '))
		{
			buf[r] = '\0';
			break;
		}
}
