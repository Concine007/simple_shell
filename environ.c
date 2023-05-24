#include "shell.h"

/**
* _myenv - prints the current env't
* @info: Structure
* Return: 0
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}
/**
* _getenv - value of an env't var
* @info: Structure
* @name: env't var
*
* Return: value
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *q;

while (node)
{
q = starts_with(node->str, name);
if (q && *q)
return (q);
node = node->next;
}
return (NULL);
}
/**
* _mysetenv - new environment variable
* @info: Structure
* Return: 0
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}
/**
* _myunsetenv - Remove an env't var
* @info: Structure
* Return:0
*/
int _myunsetenv(info_t *info)
{
int x;

if (info->argc == 1)
{
_eputs("few arguements.\n");
return (1);
}
for (x = 1; x <= info->argc; x++)
_unsetenv(info, info->argv[x]);
return (0);
}
/**
* populate_env_list - populates env't
* @info: Structure
* Return: 0
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t x;
for (x = 0; environ[x]; x++)
add_node_end(&node, environ[x], 0);
info->env = node;
return (0);
}
