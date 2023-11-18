#include "shell.h"

/**
*_free - frees a pointer and nulllifies the address
*@ptr: address of the pointer
*Return: 1 if successful, 0 otherwise
*/

int _free(void **ptr)
{
	if (ptr && *prt)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
