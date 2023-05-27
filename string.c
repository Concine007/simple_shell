#include "shell.h"

/**
 * _strtok - To k e ni zes  a st rin g ba sed  on a  del im ite r cha ract
 * @s: T he  str  in g  to  to k eni ze
 * @d: Th e d el i m it er   ch a r a c ter
 * Return: A po i nt e r  t o   the  c ur re nt t o ke n re to ken s
 */
char *_strtok(char *s, char d)
{
	char *in = NULL;
	char *re;
	int x  = 0;

	if (s != NULL)
		in = s;

	if (in == NULL)
		return (NULL);

	re = malloc(strlen(in) + 1);

	for (; in[x] != '\0'; x++)
	{
		if (in[x] != d)
			re[x] = in[x];
		else
		{
			re[x] = '\0';
			in = in + x + 1;
			return (re);
		}
	}

	re[x] = '\0';
	in = NULL;

	return (re);
}

/**
 * _strlen - r etu rn s  th e le ng t h  of   a st r ing
 * @s: t he  s tri n g  who se   len g t h to  che ck
 * Return: i nte ge r  le ng t h of  st r in g
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
 * _strcmp - c ompa ri so n of  t wo  st r a ngs.
 * @s1: t he  f ir s t s t ra n g
 * @s2: t he   s ec o n d  s tr ang
 * Return: -v e i f  s1  <  s 2,   +v  e  i f  s 1  >  s 2,   0  i f
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
 * _puts - p ri n t   a  s t ring
 * @str: st r i n g  t  o  be  p r i nt e d
 * Return: n o . pr i n t ed   ch a r a c te r s
 */
int _puts(char *str)
{
	int x;

	if (!(str))
		return (0);
	for (x = 0; str[x]; x++)
		write(STDOUT_FILENO, &str[x], 1);
	return (x);
}
