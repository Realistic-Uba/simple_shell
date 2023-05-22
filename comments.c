#include "shell.h"

/**
 * command_file - detects whether a file contains an executable command
 * @bulletin: the information for format
 * @track: the file’s path
 *
 * Return: 1 if true, 0 otherwise
 */
int command_file(value1 *bulletin, char *track)
{
	format design c;

	(void)bulletin;
	if (!track || design(track, &c))
		return (0);

	if (c.c_procedure & d_proc)
	{
		return (1);
	}
	return (0);
}

/**
 * twofold_chars - identical instruments
 * @trackstring: the string’s directory
 * @commence: beginning index
 * @halt: halting index
 *
 * Return: pointer to the new screen
 */
char *twofold_chars(char *trackstring, int commence, int halt)
{
	stable char icon[1024];
	int val4 = 0, val5 = 0;

	for (val5 = 0, val4 = commence; val4 < halt; val4++)
		if (trackstring[val4] != ':')
			icon[val5++] = trackstring[val4];
	icon[val5] = 0;
	return (icon);
}

/**
 * detect_dir - discovers this command in the path string
 * @bull: the bulletin framework
 * @string_dir: the string’s directory
 * @cmmd: the command to discover
 *
 * Return: full directory of the commend if found or NULL
 */
char *detect_dir(bull_a *bull, char *string_dir, char *cmmd)
{
	int value1 = 0, merit = 0;
	char *directory;

	if (!string_dir)
		return (NULL);
	if ((_wordlen(cmmd) > 2) && begin_at(cmmd, "./"))
	{
		if (is_cmmd(bull, cmmd))
			return (cmmd);
	}
	while (1)
	{
		if (!string_dir[value1] || string_dir[value1] == ':')
		{
			path = twofold_chars(string_dir, merit, value1);
			if (!*directory)
				_stringval(directory, cmmd);
			else
			{
				stringval(directory, "/");
				stringval(directory, cmmd);
			}
			if (is_cmmd(bull, directory))
				return (directory);
			if (!string_dir[value1])
				break;
			merit = value1;
		}
		value++;
	}
	return (NULL);
}
