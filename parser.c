#include "shell.h"

/**
*is_cmd - determines if a file is an executable
*@info: info struct
*@path: path to the file
*Return: 1if true, otherwise 0
*/

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void) info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
		return (1);
	return (0);
}

/**
*dup_chars - dupllicates characters
*@pathstr: path to the string
*@start: starting idx
*@stop: stopping idx
*Return: pointer to new buffer
*/
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buff[1024];
	int i=0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buff[k++] = pathstr[i];

	buff[k] = 0;
	return (buff);
}
/**
*find_path - finds this cmd in the path string
*@info: the info struct
*@pathstr : the path
*@cmd: the cmd to find
*Return: full path of command if found, null otherwise
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
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
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!path)
				_strcar(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
