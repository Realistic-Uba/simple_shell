#include "shell.h"

/**
 **_strncpy - this copies a string
 *@dest: dest string to be copied from the src
 *@src: the src string
 *@n: the total amount of characters to be copied
 *Return: the merged/concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
	int r, p;
	char *ptr = dest;

	r = 0;
	while (src[r] != '\0' && r < n - 1)
	{
		dest[r] = src[r];
		r++;
	}
	if (r < n)
	{
		p = r;
		while (p < n)
		{
			dest[p] = '\0';
			p++;
		}
	}
	return (ptr);
}

/**
 **_strncat - concate's two strings
 *@dest: 1st string
 *@src:  2nd string
 *@n: total amount of bytes to be used maximally
 *Return: the string that has been concatenated
*/
char *_strncat(char *dest, char *src, int n)
{
	int r, p;
	char *ptr = dest;

	r = 0;
	p = 0;
	while (dest[r] != '\0')
		r++;
	while (src[p] != '\0' && p < n)
	{
		dest[r] = src[p];
		r++;
		p++;
	}
	if (p < n)
		dest[r] = '\0';
	return (ptr);
}

/**
 **_strchr - thr prototype locates a char in a string
 *@s: the right string to be parsed
 *@c: the character to search for
 *Return: a pointer to the (s) memory-area
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
