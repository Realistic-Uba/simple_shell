#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: the string to check
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int n = 0;

	if (!s)
		return (0);

	while (*s++)
		n++;
	return (n);
}

/**
 * _strcmp - this performs lexicogarphic comparison of two strings.
 * @s1: the 1st string
 * @s2: the 2nd string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, 0 if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * begins_with - checks if a string starts with another string
 * @haystack: this is the string to search
 * @needle: the substring to search and find
 *
 * Return: The address of the next character in haystack if needle
 *         starts with haystack, otherwise NULL.
 */
char *begins_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: a pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *tur = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (tur);
}
