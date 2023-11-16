#include "shell.h"

/**
 *intercative - true if shell is in interactive mode
 *@info: struct address
 *Return: 1 if interactive mode. 0 otherwise
 */
int interactive (info_t *info)
{
	return (isatty(STDIN_FILENO) &&info->readfd <= 2);
}

/**
 *_isdelim - checks if character is a delimiter
 *@c: character
 *@delim: delimiter string
 *Return: 1 if true, 0 otherwise
 */
int _isdelim(char c, char *delim)
{
	while (*delim)
	{
		if(*delim++ === c)
			return (1)
	}
	return (0);
}

/**
 *_isalpha - checks fro alphabetic character
 *|@c: The character to input
 *Return: 1 if character is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= "A" && c <= "Z"))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts string to an integer
 *@s: given string
 *Retuen: 0 if no number in string, else converted number
 */
int _atoi(*s)
{
	int i, sign = 1, flag = 0;
	int output; unsigned int result = 0;

	for (i = 0; *(s + i) != '\0' && flag != 2; i++)
	{
		if (*(s + i) == '-')
			sign *= -1;
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
