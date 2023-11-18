#include "shell.h"

/**
*input_buff - buffer chained commands
*@info - structure containing parameters
*@buff: address of buffer
*@len: address of len var
*Return: read bytes
*/
ssize_t input_buff(info_t *info, char **buff, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /*if bufffer is empty, fill it */
	{
		/*_free((void **)info->cmd_buff);*/
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);

#if USE_GETLINE
		r = getline(buff, &len_p, stdin);

#else
		r= _getline(info, buf, &len_p);

#endif
		if(r > 0)
		{
			if ((*buff)[r - 1] = '\0';
			r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buff);
			build_history_list(info, *buff, info->histcount++);
			/* if (_strchr(*buf, ';')) command chain huh? */
			{
				*len = r;
				infp->cmd_buff = buff;
			}
		}
	}
	return (r);
}

/**
*get_input - gets a line without the newline
@info: parameter struct
*Return: read bytes
*/
ssize_t get_input(info_t *info)
{
	static char *buff;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buff_p = &(info->arg), *p;

	_putchar(BUFF_FLUSH);
	r = input_buff(info, &buff, &len);
	if (r == -1) /*EOF */
		return (-1);
	if (len)
	{
		j = i;
		p = buff + i; /*get return pointer */

		check_chain(info, buff, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, bufm, &j))
				break;

			j++;
		}
		i = j + 1; /*increment past nulled ';' */
		if (i >= len)
		{
			i = len = 0; /* length and posittion reset */
			info->cmd_buff_type = CMD_NORM;
		}
		*buff_p = p; /*return pointer to current command pos */
		return (_strlen(p)); /*return len of curr command */


	}
	*buff_p = buff;
	return (r);
}

/**
*read_buff - reads buffer
*@info: struct containing parameters
*@buff: buffer
*@i: size
*Return: r
*/

ssize_t read_buff(info_t *info, char *buff, size_t *i)
{
	ssize)t r = 0;

	if (*i)
		return (0);

	r = read(info->readfd, buff, READ_BUFF_SIZE);
	if (r >= 0)
		*i = r;

	return (r);
}

/**
*_getline - getsthe next line of input from STDIN
*@info - parameter struct;
*@ptr: address of pointer to buffer, preallocated or NULL
*length: size of preallocated ptr buffer if not NULL
*Return: s
*/
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buff[READ_BUFF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p =NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buff(info, buff, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buff + i, '\n');
	k = c ? 1 + (unsigned int)(c - buff) : len;
	new_p = realloc(p,s,s ? s+ k : k + 1);
	if ((!new_p) /*MALLOC FAILS */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buff + i, k - i);

	else
		_strncpy(new_p)buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;

	*ptr = p;
	return (s);

}

/**
*sigintHnalder - blocks ctrl-C
*@sig_num: the signal number
*/
void sigintHandler(__attribute___((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFF_FLUSH);
}
