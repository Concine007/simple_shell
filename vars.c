#include "shell.h"

/**
* is_chain - ifchain delimeter
* @info: pa ra struct
* @buf: ch ar buffer
* @p: add re ss of cu rre nt po sit io n  in buf
* Return: 1  if cha i n del imet e r, 0 ot h e rwise
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t y = *p;

	if (buf[y] == '|' && buf[y + 1] == '|')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[y] == '&' && buf[y + 1] == '&')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[y] == ';')
	{
		buf[y] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = y;
	return (1);
}
/**
* check_chain - che cks we  sho uld c onti nue c haining
* @info: th e pa rame ter str uct
* @buf: t he ch ar buf f er
* @p: ad dr ess of cu rre nt pos itio n in b uf
* @i: sta rtin g pos iti on in bu f
* @len: le ngth  of b uf
* Return: Voi d
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t y = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			y = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			y = len;
		}
	}
	*p = y;
}
/**
* replace_alias - rep la ces an ali ases str ing
* @info: th e pa ramet er st ruc t
* Return: 1 if re pla ced, 0 othe rwi se
*/
int replace_alias(info_t *info)
{
int i;
list_t *n;
char *p;
for (i = 0; i < 10; i++)
{
n = node_starts_with(info->alias, info->argv[0], '=');
if (!n)
return (0);
free(info->argv[0]);
p = _strchr(n->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}
/**
* replace_vars - rep lac es va rs in th e tok eni zed st r ing
* @info: t he par amet er s tr uct
* Return: 1 i f re place d, 0 oth er wise
*/
int replace_vars(info_t *info)
{
int i = 0;
list_t *node;
for (i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] != '$' || !info->argv[i][1])
continue;
if (!_strcmp(info->argv[i], "$?"))
{
replace_string(&(info->argv[i]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[i], "$$"))
{
replace_string(&(info->argv[i]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[i][1], '=');
if (node)
{
replace_string(&(info->argv[i]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[i], _strdup(""));
}
return (0);
}
/**
* replace_string - re pla ces st ri ng
* @old: ad dre ss of o ld st ri ng
* @new: ne w st rin
* Return: 1 if r epl ace d, 0 ot her wise
*/
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
