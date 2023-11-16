#include "shell.h"

/**
 *_env - prints current environment
 *@nfo: structure containing potential arguments
 *Return: 0
 *
 *
 */
int _env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 *_getenv gets the value of an environment variable
 *@info: structure containing args
 *@name: env variable name
 *Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 *_setenv - initialise or modify environemnt variable
 *@info - structure containing args
 *Return: 0
 */
int _setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (-1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 *_unsetenv - remove environment variable
 *@info - structure containing args
 *Return: 0
 */
int _unsetenv(info_t *info)
{
	int k;

	if (info->argc == 1)
	{
		e_puts("Argunents are less\n");
		return (1);
	}
	for (k = 0; k <= info->argc; k++)
		_unsetenv(info, info->argv[k]);
	return (0);
}

/**
 *populate_env_lsist - populate env linked list
 *@info: structure containing args
 *Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);

	info->env = node;
	return (0);
}
