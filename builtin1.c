#include "shell.h"

/**
* _myhistory - displays the historylistss
* @info: Structure
* Return: 0
*/
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}
/**
* unset_alias - sets alias
* @info: structure
* @str: string alias
* Return: 0 on success, 1 on error
*/
int unset_alias(info_t *info, char *str)
{
char *q, w;
int r;

q = _strchr(str, '=');
if (!q)
return (1);
w = *q;
*q = 0;
r = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*q = w;
return (r);
}
/**
* set_alias - sets alias to string
* @info: structure
* @str: string alias
* Return: 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
char *q;

q = _strchr(str, '=');
if (!q)
return (1);
if (!*++q)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
* print_alias - prints alias
* @node: node
* Return: 0 on success, 1 on error
*/
int print_alias(list_t *node)
{
char *q = NULL, *z = NULL;

if (node)
{
q = _strchr(node->str, '=');
for (z = node->str; z <= q; z++)
_putchar(*z);
_putchar('\');
_puts(q + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
* _myalias - mimics the alias
* @info: Structure
* Return: 0
*/
int _myalias(info_t *info)
{
int x = 0;
char *q = NULL;
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
for (x = 1; info->argv[x]; x++)
{
q = _strchr(info->argv[x], '=');
if (q)
set_alias(info, info->argv[x]);
else}
return (0);}
