#include "shell.h"

/**
* **strtow - Splitsstring into word
* @str: String
* @d: Delimeter
* Return: pointeror NULL
*/
char **strtow(char *str, char *d)
{
int x, y, z, m, n = 0;
char **a;
if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (x = 0; str[x] != '\0'; x++)
if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
n++;
if (n == 0)
return (NULL);
a = malloc((1 + n)*sizeof(char *));
if (!a)
return (NULL);
for (x = 0, y = 0; y < n; y++)
{
while (is_delim(str[x], d))
x++;
z = 0;
while (!is_delim(str[x + z], d) && str[x + z])
z++;
a[y] = malloc((z + 1) * sizeof(char));
if (!a[y])
{
for (z = 0; z < y; z++)
free(a[z]);
free(a);
return (NULL);
}
for (m = 0; m < z; m++)
a[y][m] = str[x++];
a[y][m] = 0;
}
a[y] = NULL;
return (a);
}
/**
* **strtow2 - Splitstring
* @str: String
* @d: Delimeter
* Return: Pointer
*/
char **strtow2(char *str, char d)
{
int x, y, z, m, n = 0;
char **a;
if (str == NULL || str[0] == 0)
return (NULL);
for (x = 0; str[x] != '\0'; x++)
if ((str[x] != d && str[x + 1] == d) ||
(str[x] != d && !str[x + 1]) || str[x + 1] == d)
n++;
if (n == 0)
return (NULL);
a = malloc((1 + n)*sizeof(char *));
if (!a)
return (NULL);
for (x = 0, y = 0; y < n; y++)
{
while (str[x] == d && str[x] != d)
x++;
z = 0;
while (str[x + z] != d && str[x + z] && str[x + z] != d)
z++;
a[y] = malloc((z + 1) * sizeof(char));
if (!a[y])
{
for (z = 0; z < y; z++)
free(a[z]);
free(a);
return (NULL);
}
for (m = 0; m < z; m++)
a[y][m] = str[x++];
a[y][m] = 0;
}
a[y] = NULL;
return (a);
}
