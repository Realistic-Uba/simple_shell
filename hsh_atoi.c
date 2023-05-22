#include "shell.h"

/**
 * interactive - when the shell is in interactive mode, this returns true.
 * @info: show the struct address
 *
 * Return: when in interactive mode, return 1, otherwise 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - determines whether a character is a delimeter
 * @c: the char to be verified
 * @delim: this illustrates the delimeter string
 * Return: if true, returns 1, otherwise 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - this checks the shell for alphabetic characters
 *@c: input for characters
 *Return: if c is alphabetical, return 1, otherwise 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - using this, a string is turned into an integer
 *@s: to be converted string
 *Return: 0 if the string contains no numbers; else, a converted number
 */

int _atoi(char *s)
{
	int k, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (k = 0;  s[k] != '\0' && flag != 2; k++)
	{
		if (s[k] == '-')
			sign *= -1;

		if (s[k] >= '0' && s[k] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[k] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
