#include "shell.h"

/**
* interactive - Return true if shellinteractiv
* @info: Structaddress
*
* Return: 1 if interactive, else 0
*/

int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - Checks the character whether delimeter
* @c: the char
* @delim: delimeter string
* Return: 1 if true, else 0
*/
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}
/**
* _isalpha - Check Alphabetic character
* @c: The character to input
* Return: 1 if alphabetic, else 0
*/
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
/**
* _atoi - Converts string to integer
* @s: string to be converted
* Return: 0
*/
int _atoi(char *s)
{
int x, n = 1, f = 0, o;
unsigned int r = 0;

for (x = 0; s[x] != '\0' && f != 2; x++)
{
if (s[x] == '-')
n *= -1;
if (s[x] >= '0' && s[x] <= '9')
{
f = 1;
r *= 10;
r += (s[x] - '0');
}
else if (f == 1)
f = 2;
}
if (n == -1)
o = -r;
else
o = r;
return (o);
}
