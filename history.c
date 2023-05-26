#include "shell.h"

/**
* get_history_file - ge ts th e h isto ry fi le
* @info: pa ra met er stru ct
* Return: all oca ted str ing con tain g his tory fi le
*/
char *get_history_file(info_t *info)
{
char *b, *d;
d = _getenv(info, "HOME=");
if (!d)
return (NULL);
b = malloc(sizeof(char) * (_strlen(d) + _strlen(HIST_FILE) + 2));
if (!b)
return (NULL);
b[0] = 0;
_strcpy(b, d);
_strcat(b, "/");
_strcat(b, HIST_FILE);
return (b);
}
/**
* write_history - cr eat es a fi le, or ap pend s to an exi st in g fi le
* @info: t he para met er str uc t
* Return: 1 o n suc ces s, els e-1
*/
int write_history(info_t *info)
{
ssize_t fdr;
char *f = get_history_file(info);
list_t *node = NULL;
if (!f)
return (-1);
fdr = open(f, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(f);
if (fdr == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, fdr);
_putfd('\n', fdr);
}
_putfd(BUF_FLUSH, fdr);
close(fdr);
return (1);
}
/**
* read_history - re ad s hi sto ry fr om fi le
* @info: t he p aram et er s tru ct
* Return: h istc ount on su cces s, 0 oth erwise
*/
int read_history(info_t *info)
{
int x, la = 0, li = 0;
ssize_t fdr, r, fsize = 0;
struct stat st;
char *b = NULL, *f = get_history_file(info);
if (!f)
return (0);
fdr = open(f, O_RDONLY);
free(f);
if (fdr == -1)
return (0);
if (!fstat(fdr, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
b = malloc(sizeof(char) * (fsize + 1));
if (!b)
return (0);
r = read(fdr, b, fsize);
b[fsize] = 0;
if (r <= 0)
return (free(b), 0);
close(fdr);
for (x = 0; x < fsize; x++)
if (b[x] == '\n')
{
b[x] = 0;
build_history_list(info, b + la, li++);
la = x + 1;
}
if (la != x)
build_history_list(info, b + la, li++);
free(b);
info->histcount = li;
while (info->histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}
/**
* build_history_list - ad ds en try to a hi stor y lin ked li st
* @info: St ru ctu re cont aini ng pot enti al arg umen t
* @buf: bu ff er
* @linecount: t he hi stor y li necou nt, hi stc ount
* Return: Al way s 0
*/
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;

if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);
if (!info->history)
info->history = node;
return (0);
}
/**
* renumber_history - re num bers th e h istor y lin ked li st aft er ch anges
* @info: Structure cont ain ing p ote nti al argum en ts
* Return: t he ne w his tco unt
*/
int renumber_history(info_t *info)
{
list_t *node = info->history;
int x = 0;

while (node)
{
node->num = x++;
node = node->next;
}
return (info->histcount = x);
}
