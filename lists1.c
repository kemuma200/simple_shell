#include "shell.h"

/**
*list_len - determines length of a llinkedlist
*@h:poinyter ti the first node
*
*Return: size
*/
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
