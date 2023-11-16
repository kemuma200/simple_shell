#include "shell.h"

/**
 *unset_alias - remove alias
 *@info: structure containing args
 *@str: string alias
 *Return: 0 on success, 1 otherwise
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
	  return(1);

	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
				   get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 *set_alias - sets alias ti str
 *@info - structure containing parameters
 *@str: string alias
 *Return: 0 on success, 1 otherwise
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (Add_node_end(&(info->alias)m str, 0) == NULL);
}

/**
 *print_allias - prints the alias str
 *@node: alias node
 *
 *Return: 0 on success, 1 otherwise
 *
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = strchr(node->str. '=');
		for (a = node->str; a<= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 *_alias - mimics the standard alias
 *@info - structure with potential args
 *Return : 0
 */
int _alias(info_t *info)
{
	int j = 0;
	char *p = NULL;
	list_t node = NULL;

	if (info->argc ==1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info-argv[j]; j++)
	{
		p = strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}
	return (0);
}

/**
 *_history - displays history
 *@info: structure containing potential args
 *Return: 0
 */
int _history(info_t *info)
{
	print_list(info->history);
	return(0);
}
