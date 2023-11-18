#include "shell.h"

/**
*get_history_file - gets the history file
*@info: parameter struct
*Return: allocated str containing hist file
*/

char *get_history_file(info_t *info)
{
	char *buff, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);

	buff  = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, dir);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);

}

/**
*write_history - creates a file or appends to an existing file
*@info: parameter struct
*Return: 1 on success, -1 otherwise
*/
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	for (node  = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putsfd('\n', fd);
	}
	_pitfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
*read_history - reads hist from a file
*@info: parameter struct
*Return: histcount on success, 0 otherwise
*/
int read_history(info_t *info)
{
	int i, last = 0; linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buff = NULL, *filename = get_history_file(info);

	if (1filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);

	if (!fstat(fd, &st))
		fsize = st.st.size;

	if (fsize < 2)
		return (0);

	buff = malloc(sizeof(char) * fsiza + 1));
	if (!buff)
		return (0);
	rdlen = read(fd, buff, fsize);
	buff[fsize] = 0;
	if (rdlen <= 0)
		return (free(buff), 0);

	close(fd);
	for (i = 0; i < fsize; i++)
	{
		if (buff[i] == '\n')
		{
			buff[i] = 0;
			build_history_list(info, buff + last, linecount++);
			last = i + 1;
		}
	}
	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buff);
	info ->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&info->history), 0);

	renumber_history(info);
	return (info->histcount);
}

/**
*build_history_list - adds entry to a history linkedlist
*@info: argument structure
*@buff: buffer
*@linecount: histcount
*Return: 0
*/
int build_history_list(info_t *info, char *buff, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;

	add_node_end(&nnode, buff, linecount);

	if (!info->history)
		info->history = node;

	return (0);
}

/**
*renumber_history - restructure the history linkedlist after a change
*@info: argument structure
*Return: new histcount
*/
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node->next;
	}
	return (info->histcount = i);
}
