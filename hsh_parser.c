#include "shell.h"

/**
 * is_cmd - this is to ascertain if a file is an executable command
 * @info: this the info struct
 * @path: this represents the path to the file
 * Return: if true,1 else 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - this replicates characters
 * @pathstr: this is the PATH string
 * @start: this represents starting index
 * @stop: for stopping index
 * Return: a pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int a = 0, b = 0;

	for (b = 0, a = start; a < stop; a++)
		if (pathstr[a] != ':')
			buf[b++] = pathstr[a];
	buf[b] = 0;
	return (buf);
}

/**
 * find_path - this finds the particular command in the PATH string
 * @info: it represents the info struct
 * @pathstr: this is the PATH string
 * @cmd: the command to find
 * Return: the full path of command if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int g = 0, curr_area = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && begins_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[g] || pathstr[g] == ':')
		{
			path = dup_chars(pathstr, curr_area, g);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[g])
				break;
			curr_area = g;
		}
		g++;
	}
	return (NULL);
}
