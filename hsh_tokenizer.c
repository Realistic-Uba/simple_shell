#include "shell.h"

/**
 * **strtow - this is to splits a str into words. Repeat delimiters are ignored
 * @str: this is the input string
 * @d: this is the delimeter string
 * Return: a pointer to an array of strings, or Nothing on failure
 */

char **strtow(char *str, char *d)
{
	int o, j, x, m, wordNumber = 0;
	char **stgs;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (o = 0; str[o] != '\0'; o++)
		if (!is_delim(str[o], d) && (is_delim(str[o + 1], d) || !str[o + 1]))
			wordNumber++;

	if (wordNumber == 0)
		return (NULL);
	stgs = malloc((1 + wordNumber) * sizeof(char *));
	if (!stgs)
		return (NULL);
	for (o = 0, j = 0; j < wordNumber; j++)
	{
		while (is_delim(str[o], d))
			o++;
		x = 0;
		while (!is_delim(str[o + x], d) && str[o + x])
			x++;
		stgs[j] = malloc((x + 1) * sizeof(char));
		if (!stgs[j])
		{
			for (x = 0; x < j; x++)
				free(stgs[x]);
			free(stgs);
			return (NULL);
		}
		for (m = 0; m < x; m++)
			stgs[j][m] = str[o++];
		stgs[j][m] = 0;
	}
	stgs[j] = NULL;
	return (stgs);
}

/**
 * **strtow2 - this function to splits a string into words
 * @str: this is the input string
 * @d: this is the delimeter
 * Return: a pointer to an array of strs, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int o, p, b, m, wordNumber = 0;
	char **words;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (o = 0; str[o] != '\0'; o++)
		if ((str[o] != d && str[o + 1] == d) ||
		    (str[o] != d && !str[o + 1]) || str[o + 1] == d)
			wordNumber++;
	if (wordNumber == 0)
		return (NULL);
	words = malloc((1 + wordNumber) * sizeof(char *));
	if (!words)
		return (NULL);
	for (o = 0, p = 0; p < wordNumber; p++)
	{
		while (str[o] == d && str[o] != d)
			o++;
		b = 0;
		while (str[o + b] != d && str[o + b] && str[o + b] != d)
			b++;
		words[p] = malloc((b + 1) * sizeof(char));
		if (!words[p])
		{
			for (b = 0; b < p; b++)
				free(words[b]);
			free(words);
			return (NULL);
		}
		for (m = 0; m < b; m++)
			words[p][m] = str[o++];
		words[p][m] = 0;
	}
	words[p] = NULL;
	return (words);
}
