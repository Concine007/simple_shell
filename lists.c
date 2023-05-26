#include "shell.h"
/**
* add_node - a dds  a node  to  th sta rt o f th e li st
* @head: a ddr e ss  of poi nt er to he ad no de
* @str: s tr fi eld  of n od e
* @num: nod e ind ex se d  b y his tor y
* Return: si ze o f li st
*/
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *new_head;
if (!head)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;
if (str)
{
new_head->str = _strdup(str);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *head;
*head = new_head;
return (new_head);
}
/**
* add_node_end - ad ds a no de t o t he en d of t he lis t
* @head: add re ss  of poi nt er to he ad no de
* @str: s tr fie ld of n od e
* @num: no de in dex use d by his tory
* Return: s i ze of l is t
*/
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *new, *node;
if (!head)
return (NULL);
node = *head;
new = malloc(sizeof(list_t));
if (!new)
return (NULL);
_memset((void *)new, 0, sizeof(list_t));
new->num = num;
if (str)
{
new->str = _strdup(str);
if (!new->str)
{
free(new);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new;
}
else
*head = new;
return (new);
}
/**
* print_list_str - p rint s on ly th e st r el eme nt of a lis t_t li nked
* @h: po in ter to fi rst no de
* Return: si ze  of l ist
*/
size_t print_list_str(const list_t *h)
{
size_t x = 0;
while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
x++;
}
return (x);
}
/**
* delete_node_at_index - de let es no de at gi ven in dex
* @head: ad dre ss of po int er to f irst no de
* @index: ind ex of no de to del ete
* Return: 1 o n s ucce s s, 0 on fai lu re
*/
int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int x = 0;
if (!head || !*head)
return (0);
if (!index)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}
node = *head;
while (node)
{
if (x == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
x++;
prev_node = node;
node = node->next;
}
return (0);
}
/**
* free_list - fr ee sa ll no des o f a li st
* @head_ptr: ad dr e ss of po int er to he ad no de
* Return: vo id
*/
void free_list(list_t **head_ptr)
{
list_t *node, *next_n, *head;
if (!head_ptr || !*head_ptr)
return;
head = *head_ptr;
node = head;
while (node)
{
next_n = node->next;
free(node->str);
free(node);
node = next_n;
}
*head_ptr = NULL;
}
