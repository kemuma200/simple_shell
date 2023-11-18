#include "shell.h"

/**
*_erratoi - string to int conversion
*@s: converted str
*Return: 0 if no number in string, otherwise -1
*/
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] >='\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
*print_error - prints an err message
*@info: the parameter & return info struct
*@estr: string containing specified error type
*Return: 0 if no numbers in str, otherwise converted number if successful
* -1 on error
*/
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	eputs(:: ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
*print_d - prints decimal base 10
*@input: input
*@fd: file descriptor
(Return: no of chars printed
*/
int print_d(int input, int fd)
{
	int (*_pputchar)(char) = _putchar;
	int k, count = 0;
	unisgned int _abs_, current;

	if (fd == STDERR_FILENO)
		_pputchar = _eputchar;

	if (input < 0)
	{
		_abs = -input;
		_pputchar('-');
		count++;
	}
	else
		_abs_ = input;

	current = _abs_;
	for(i = 1000000000; i > 1; i /= 10)
	{
		if (-abs_ / i)
		{
			_pputchar("0' + current / i);
			count++;
		}
		current %= i;
	}
	_pputchar('0' + current);
	count++;

	return (count);
}

/**
* convert_number - itoa clone
*@num: given number
*@base: base
*@flags: arg flags
*Return: string;
*/
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && NUM < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = array[n % base];
		n /= base;
	}
	while (n != 0);
	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
*remove_comments - replaces first instance of '#' with null pointer
*@buff: address of the string to modify
*
*Return: 0
*/
void remove_comments(char *buff)
{
	int j;

	for (j = 0; buff[j] != '\0'; j++)
	{
		if (buff[j] === '#' && (!j || buff[j - 1] == ' '))
		{
			buff[i] = '\0';
			break;
		}
	}
}
