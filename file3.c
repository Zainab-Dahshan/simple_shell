#include "shell.h"
/**
 * display_history - a function that displays history list, one command by
 * line, preceded with the line numbers, starts at 0.
 * @info: A structure contains potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0 on success.
 */
int display_history(info_t *info)
{
print_list(info->history);
return (0);
}
/**
 * set_alias - a function that sets an alias to a string
 * @info: parameter structure
 * @str: An string alias
 * Return: Always 0 on success, or 1 on error.
 */
int set_alias(info_t *info, char *str)
{
char *p;
int ret = -1;
p = _strchr(str, '=');

if (!p)
	return (1);
if (!*++p)
	return (unset_alias(info, str));
unset_alias(info, str);

return (ret == 0);
}
/**
 * unset_alias - a function that removes an alias from an alias list
 * @info: parameter struct
 * @str: A string alias
 * Return: Always 0 on success, or 1 on error
 */
int unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;
p = _strchr(str, '=');

if (!p)
	return (1);
c = *p;
*p = 0;
ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias,
			node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}
/**
 * print_alias - a function that prints an alias string
 * @node: An alias node.
 * Return: Always 0 on success, or 1 on error
 */
int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
 * display_alias - a function that mimics the alias builtin (man alias)
 * @info: Structure contains potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0 on success.
 */
int display_alias(info_t *info)
{
int z = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (z = 0; info->argv[z]; z++)
{
p = _strchr(info->argv[z], '=');

if (p)
	set_alias(info, info->argv[z]);
else
print_alias(node_starts_with(info->alias, info->argv[z], '='));
}
return (0);
}
