#include "shell.h"
/**
* _memset - fil ls mem ory w ith a con st ant b y te
* @s: th e po int er to  the  mem ory  ar ea
* @b: th e b yt e  to fil l  *s  w i th
* @n: th e a mo un t  of  by t e s to  be  fi  lled
* Return: a p oi nter to  the  me mo ry ar ea  s
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int x;

for (x = 0; x < n; x++)
s[x] = b;
return (s);
}
/**
* ffree - fr ee s a s tri ng o f str i n gs
* @pp: s tr ing  o f s tr i ng s
*/
void ffree(char **pp)
{
char **q = pp;
if (!pp)
return;
while (*pp)
free(*pp++);
free(q);
}
/**
* _realloc - re al loc ates  a b lo ck of  me mor y
* @ptr: po in te r to  pr ev ious  ma ll oc'at ed blo ck
* @old_size: b yt e siz e  of p revio us bl ock
* @new_size: b yte  siz e of  ne w  b lo ck
* Return: poi nte r to  da o l'bl ock  na m e.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
p = malloc(new_size);
if (!p)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
