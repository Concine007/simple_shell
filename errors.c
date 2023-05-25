#include "shell.h"

/**
* _eputs - print input string
* @str: String to be print
* Return: 0
*/
void _eputs(char *str)
{
int x = 0;

if (!str)
return;
while (str[x] != '\0')
{
_eputchar(str[x]);
x++;
}
}
/**
* _eputchar - writes char c to stder
* @c: character
* Return: 1
*/
int _eputchar(char c)
{
static int x;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
{
write(2, buf, x);
x = 0;
}
if (c != BUF_FLUSH)
buf[x++] = c;
return (1);
}
/**
* _putfd - writes char c to fd
* @c: character
* @fd: filedescriptor
* Return: 1
*/
int _putfd(char c, int fd)
{
static int x;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
{
write(fd, buf, x);
x = 0;
}
if (c != BUF_FLUSH)
buf[x++] = c;
return (1);
}
/**
* _putsfd - Print string
* @str: string
* @fd: filedescriptor
* Return: number of chars
*/
int _putsfd(char *str, int fd)
{
int x = 0;
if (!str)
return (0);
while (*str)
{
x += _putfd(*str++, fd);
}
return (x);
}
