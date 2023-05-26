#include "shell.h"

/**
* _myexit - Exit Shell
* @info: Structure potential arg.
* Return: exit given status
*/

int _myexit(info_t *info)
{
int e;

if (info->argv[1])
{
e = _erratoi(info->argv[1]);
if (e == -1)
{
info->status = 2;
print_error(info, "ilegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}
/**
* _mycd- Changes the cd process
* @info: structure potential arg
* Return: 0
*/
int _mycd(info_t *info)
{
char *a, *d, buffer[1024];
int c;

a = getcwd(buffer, 1024);
if (!a)
_puts(" >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
d = _getenv(info, "home=");
if (!d)
c = chdir((d = _getenv(info, "pwd=")) ? d : "/");
else
c = chdir(d);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "oldpwd="))
{
_puts(a);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "oldpwd=")), _putchar('\n');
c = chdir((d = _getenv(info, "oldpwd=")) ? d : "/");
}
else
c = chdir(info->argv[1]);
if (c == -1)
{
print_error(info, "Can't cd  ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
}
_setenv(info, "oldpwd", _getenv(info, "pwd="));
_setenv(info, "pwd", getcwd(buffer, 1024));
return (0);
}
/**
* _myhelp - Changes the cd process
* @info: Structure
* Return: 0
*/
int _myhelp(info_t *info)
{
char **a;

a = info->argv;
_puts("help\n");
if (0)
_puts(*a);
return (0);
}
