#include "shell.h"

/**
**_strncpy - Copies a str
*@dest: destination
*@src: source
*@n: amount
*Return: string
*/
char *_strncpy(char *dest, char *src, int n)
{
int x, y;
char *z = dest;
x = 0;
while (src[x] != '\0' && x < n - 1)
{
dest[x] = src[x];
x++;
}
if (x < n)
{
y = x;
while (y < n)
{
dest[y] = '\0';
y++;
}
}
return (z);
}
/**
**_strncat - Concatenate strings
*@dest: destination
*@src: source
*@n: amount
*Return: String
*/
char *_strncat(char *dest, char *src, int n)
{
int x = 0, y = 0;
char *z = dest;

while (dest[x] != '\0')
x++;
while (src[y] != '\0' && y < n)
{
dest[z] = src[y];
x++;
y++;
}
if (y < n)
dest[x] = '\0';
return (z);
}
/**
**_strchr - locates string
*@s: string
*@c: character
*Return: s
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');
return (NULL);
}
