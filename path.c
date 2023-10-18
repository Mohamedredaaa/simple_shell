#include "shell.h"



/**
 * dup_chars - Duplicates characters from a specified range in the PATH string.
 * @pathstr: The PATH string to extract characters from.
 * @start: The starting index of the range.
 * @stop: The stopping index of the range.
 * This function duplicates characters from the specified range in the 'pathstr' and
 * returns a pointer to a new buffer containing the duplicated characters.
 *
 * Return: A pointer to the new buffer with duplicated characters.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int e = 0, r = 0;

	for (r = 0, e = start; e < stop; e++)
		if (pathstr[e] != ':')
			buf[r++] = pathstr[e];
	buf[r] = 0;
	return (buf);
}


/**
 * is_cmd - Determines if a file at the given path is an executable command.
 * @info: The information struct.
 * @path: The path to the file to be checked.
 *
 * This function examines whether the file at the specified 'path' is an executable command.
 * It returns 1 if the file is a valid command, and 0 otherwise.
 *
 * Return: 1 if the file is an executable command, 0 otherwise.
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
 * find_path - Searches for the given command in the PATH string.
 * @info: The information struct.
 * @pathstr: The PATH string to search within.
 * @cmd: The command to find.
 * This function searches for the specified 'cmd' within the 'pathstr,' which typically
 * contains a list of directories in the system's PATH. If the command is found, it returns
 * the full path to the command; otherwise, it returns NULL.
 *
 * Return: The full path of the 'cmd' if found, or NULL if not found.
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int w = 0, crpos = 0;
	char *path;
	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[w] || pathstr[w] == ':')
		{
			path = dup_chars(pathstr, crpos, w);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[w])
				break;
			crpos = w;
		}w++;
	}
	return (NULL);
}
