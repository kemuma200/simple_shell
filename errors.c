#include "shell.h"

/**
*_e_puts - prints an input string
*@str: string
*/
void _eputs(char *str)
{
	int i = 0;
	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i];
		i++;
	}
}

/**
*_eputchar - writes the char to stderr
*@c: the character to print
*Return: 1 on success, -1 otherwise
*/
int _eputchar(char c)
{
	static int o;
	static char buf[WRITE_BUFF_SIZE];

	if (C!= BUFF_FLUSH || o >= WRITE_BUFF_SIZE)
	{
		write(2, buff, o);
		o = 0;
	}
	if (c != BUFF_FLUSH)
		buff[o++] = c;
	return (1);
}

/**
*_putfd - writes the character c to a given fd
*@c: the character to print
*@fd: the file descriptor to write to
*Return: 1 on success, -1 otherwise
*/
int _putfd(char c, int fd)
{
	static int i;
	static char buff[WRITE_BFF_SIZE]
	if (c == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
	{
		write(fd, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);

}

/**
*_putsfd - prints an input string
*@str: the string to be printed
*@fd: the file descriptor
*Return: the number of characters put
*/
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
		i += _putfd(*str++, fd);
	return (i);
}
