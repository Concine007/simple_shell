#include "shell.h"

/**
* get_environ - re tur ns th e st rin g ar ray c op y of ou r en viron
* @info: Stru ctu re cont ain ing pot ent ial arg um en ts
* Return: Al wa ys 0
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}
return (info->environ);
}
/**
* _unsetenv - R emo ve an en viro nme nt var iable
* @info: Str u ctu re con t aini ng p oten t ial ar gum en ts
* @var: t he s tri ng en v v ar prop ert y
* Return: 1 o n de let e, 0 ot he rwi se
*/
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t x = 0;
char *p;

if (!node || !var)
return (0);
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
info->env_changed = delete_node_at_index(&(info->env), x);
x = 0;
node = info->env;
continue;
}
node = node->next;
x++;
}
return (info->env_changed);
}
/**
* _setenv - In itia liz e a ne w en viro nmen t v aria ble
* @info: S tru ctu re c ont aini ng p ote nti al arg umen ts
* @var: th e st rin g en v va r pr ope rty
* @value: t he st ri ng en v v ar v al ue
* Return: Al way s 0
*/
int _setenv(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *p;

if (!var || !value)
return (0);
buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = info->env;
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
}
