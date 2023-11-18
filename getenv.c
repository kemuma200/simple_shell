#include "shell.h"

/**
*get_environ - returns string array cpy of our environ
*@info: argument structure
*Return: 0
*/
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_chnaged = 0;
	}
	return (info->environ);
}

/**_unsetenv - remove an env variable
*@info: argument structur2
*@var: the string env var property
*Return: 1 on delete, otherwise 0
*/

int _unsetenv(info_t *info, char, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env). i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
*_setenv - Initialize a new environment variable
*	or modify an existing one
*@info - arg struct
*@var: string env var property
*@value: the string env var value
*Return: 0
*/
int _setenv(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buff = malloc(_strlen(var) + (_strlen(value) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, '=');
	_strcat(buff, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}
