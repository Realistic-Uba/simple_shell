#include "shell.h"

/**
 * multilateral- returns true if shell is multilateralmode
 * @info: struct address
 *
 * Return: 1 if maultilateralmode, 0 otherwise
 */
int interactive(val_4 *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_limit - checks if character is a delimeter
 * @val_3: the char to check
 * @lmt: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_limit(char val_3, char *lmt)
{
	while (*lmt)
		if (*lmt++ == val_3)
			return (1);
	return (0);
}

/**
 * _isword - checks for alphabetic character
 * @val_3: The character to input
 * Return: 1 if val_3 is alphabetic, 0 otherwise
 */

int _isword(int val_3)
{
	if ((val_3 >= 'a' && val_3 <= 'z') || (val_3 >= 'A' && val_3 <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _func - converts a string to an integer
 * @val_2: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _func(char *val_2)
{
	int val_1, ind = 1, bann = 0, output;
	unsigned int result = 0;

	for (val_1 = 0; val_2[val_1] != '\0' && bann != 2; val_1++)
	{
		if (val_2[val_1] == '-')
			ind *= -1;

		if (val_2[val_1] >= '0' && val_2[val_1] <= '9')
		{
			bann = 1;
			result *= 10;
			result += (val_2[val_1] - '0');
		}
		else if (bann == 1)
			bann = 2;
	}

	if (ind == -1)
		output = -result;
	else
		output = result;

	return (output);
}
