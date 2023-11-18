#include "shell.h"

/**
*_strncpy - cpies a str
*@dest: destination
*@src: source str
*@n: no of chars to be copied
*Return: concatenated str
*/
char *_strncpy(char *dest, char *src, int n)
{
	int j, k;
	char *p = dest;

	j = 0;
	while (src[j] != '\0' && j < n - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (i < n)
	{
		k = j;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
*_strncat - concats two strings
*@dest: firts str
*@src: second str
*@n: bytes to be used
*Return: concatenated str
*/
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0; j = 0;
	while (Dest[i] != '\0)
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++; j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
*_strchr - locates char in str
*@s: parsed str
*@c: character to look out for
*Return: (s) a pointer to the meory area s
*/
char *_strchr(char *s, char c)
{
	do
	{
		if(*s == c)
			return (s);
	}
	while (*s++ != '\0');

	return (NULL);
}
