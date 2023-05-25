#include "shell.h"

/**
* hsh - main sheell looop
* @info: the paract
* @av: the argum
* Return: 0
*/
int hsh(info_t *info, char **av)
{
ssize_t x = 0;
int z = 0;

while (x != -1 && z != -2)
{
clear_info(info);
if (interactive(info))
_puts("$ ");
_eputchar(BUF_FLUSH);
x = get_input(info);
if (x != -1)
{
set_info(info, av);
z = find_builtin(info);
if (z == -1)
find_cmd(info);
}
else if (interactive(info))
_putchar('\n');
free_info(info, 0);
}
write_history(info);
free_info(info, 1);
if (!interactive(info) && info->status)
exit(info->status);
if (z == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}
return (z);
}
/**
* find_builtin - fiinds a buiiltin command
* @info: the paramet & returnn infoo struct
* Return: -1
*/
int find_builtin(info_t *info)
{
int x, z = -1;
builtin_table builtintbl[] = {
{"exit", _myexit},
{"env", _myenv},
{"help", _myhelp},
{"history", _myhistory},
{"setenv", _mysetenv},
{"unsetenv", _myunsetenv},
{"cd", _mycd},
{"alias", _myalias},
{NULL, NULL}
};
for (x = 0; builtintbl[x].type; x++)
if (_strcmp(info->argv[0], builtintbl[x].type) == 0)
{
info->line_count++;
z = builtintbl[x].func(info);
break;
}
return (z);
}
/**
* find_cmd - fiinds a command
* @info: the parameteer
* Return: void
*/
void find_cmd(info_t *info)
{
char *path = NULL;
int x, y;
info->path = info->argv[0];
if (info->linecount_flag == 1)
{
info->line_count++;
info->linecount_flag = 0;
}
for (x = 0, y = 0; info->arg[x]; y++)
if (!is_delim(info->arg[x], " \t\n"))
y++;
if (!k)
return;
path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
if (path)
{
}
else
{
}
}
info->path = path;
fork_cmd(info);
if ((interactive(info) || _getenv(info, "PATH=")
|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
fork_cmd(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
print_error(info, "not found\n");
}
/**
* fork_cmd - foorks an exeec threead to run cmd
* @info: the parameterr
* Return: void
*/
void fork_cmd(info_t *info)
{
pid_t child_pid;
child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(info->path, info->argv, get_environ(info)) == -1)
{
free_info(info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
}
}
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
print_error(info, "Permission denied\n");
}
