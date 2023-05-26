#include "shell.h"

/**
* _strcpy - Copiesstring
* @dest: destination
* @src: source
* Return: pointer
*/
char *_strcpy(char *dest, char *src)
{
int x = 0;

if (dest == src || src == 0)
return (dest);
while (src[x])
{
dest[x] = src[x];
x++;
}
dest[x] = 0;
return (dest);
}
/**
* _strdup - duplicates
* @str: the string
* Return: pointer
*/
char *_strdup(const char *str)
{
int l = 0;
char *r;

if (str == NULL)
return (NULL);
while (*str++)
l++;
r = malloc(sizeof(char) * (l + 1));
if (!r)
return (NULL);
for (l++; l--;)
r[l] = *--str;
return (r);
}
/**
* _puts - Inputstring
* @str: string
* Return: nothing
*/
void _puts(char *str)
{
int x = 0;
if (!str)
return;
while (str[x] != '\0')
{
_putchar(str[x]);
x++;
}
}
/**
* _putchar - writesthecharacterctostdout
* @c: Thecharactertoprint
* Return: success
*/
int _putchar(char c)
{
static int x;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
{
write(1, buf, x);
x = 0;
}
if (c != BUF_FLUSH)
buf[x++] = c;
return (1);
}
