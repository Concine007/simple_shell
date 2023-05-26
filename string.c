#include "shell.h"

/**
* _strlen - ReturnslengthOfstring
* @s: string
* Return: Integer
*/

int _strlen(char *s)
{
int x = 0;
if (!s)
return (0);
while (*s++)
x++;
return (x);
}
/**
* _strcmp - LexicogarphicOfstrangs.
* @s1: 1 strang
* @s2: 2 strang
* Return: neg, pos, zero
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}
/**
* starts_with - needlestartshaystack
* @haystack: string
* @needle: substring
* Return: addressor NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
* _strcat - Concatenatestrings
* @dest: dest
* @src: source
* Return: pointer to dest
*/
char *_strcat(char *dest, char *src)
{
char *r = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (r);
}
