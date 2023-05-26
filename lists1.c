#include "shell.h"

/**
* list_len - det erm ines len gth of lin ked list
* @h: po int er to fi rst no de
* Return: si ze of li st
*/
size_t list_len(const list_t *h)
{
size_t x = 0;
while (h)
{
h = h->next;
x++;
}
return (x);
}
/**
* list_to_strings - ret urn s an ar ray of  str ing s of t he l is t->s tr
* @head: po int er to fir st no de
* Return: ar r ay of str ing s
*/
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t x = list_len(head), y;
char **strs;
char *str;
if (!head || !x)
return (NULL);
strs = malloc(sizeof(char *) * (x + 1));
if (!strs)
return (NULL);
for (x = 0; node; node = node->next, x++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
}
for (y = 0; y < x; y++)
free(strs[y]);
free(strs);
return (NULL);
str = _strcpy(str, node->str);
strs[x] = str;
}
strs[x] = NULL;
return (strs);
}
/**
* print_list - pr ints  all  ele ment s of  a li st_t l ink ed li st
* @h: po in ter to  fir st no de
* Return: si ze of  lis t
*/
size_t print_list(const list_t *h)
{
size_t x = 0;
while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
x++;
}
return (x);
}
/**
* node_starts_with - ret ur ns nod e wh ose str ing st ar ts wi th pre fix
* @node: po int er to li st h ead
* @prefix: st ring  to ma tch
* @c: th e ne xt ch arac ter af ter pr efi x to mat ch
* Return: ma tch  nod e or  nul l
*/
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;
while (node)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}
/**
* get_node_index - get s th e ind ex of  a n ode
* @head: p oin ter to  li st h ead
* @node: po in ter to  the  no de
* Return: in de x of  no de or -1
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t x = 0;
while (head)
{
if (head == node)
return (x);
head = head->next;
x++;
}
return (-1);
}
