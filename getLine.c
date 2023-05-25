#include "shell.h"

/**
* input_buf - Buffers
* @info: para struct
* @buf: address buf
* @len: address of lenr
* Return: byt read
*/
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t a = 0;
size_t l = 0;

if (!*len)
{
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
a = getline(buf, &len_p, stdin);
#else
#endif
a = _getline(info, buf, &l);
if (a > 0)
{
if ((*buf)[a - 1] == '\n')
{
}
(*buf)[a - 1] = '\0';
a--;
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
{
*len = a;
info->cmd_buf = buf;
}
}
}
return (a);
}
/**
* get_input - getss newline
* @info: para struct
* Return: reads bytess
*/
ssize_t get_input(info_t *info)
{
static char *buf;
static size_t x, y, l;
ssize_t z = 0;
char **buf_p = &(info->arg), *p;

_putchar(BUF_FLUSH);
z = input_buf(info, &buf, &l);
if (z == -1)
return (-1);
if (l)
{
y = x;
p = buf + x;
check_chain(info, buf, &y, x, l);
while (y < l)
{
if (is_chain(info, buf, &y))
break;
y++;
}
x = y + 1;
if (x >= l)
{
x = l = 0;
info->cmd_buf_type = CMD_NORM;
}
*buf_p = p;
return (_strlen(p));
}
*buf_p = buf;
return (z);
}
/**
* read_buf - reeads a buuffer
* @info: paraa struct
* @buf: buffer
* @i: sizeee
* Return: z
*/
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t z = 0;
if (*i)
return (0);
z = read(info->readfd, buf, READ_BUF_SIZE);
if (z >= 0)
*i = z;
return (z);
}
/**
* _getline - the nextt linee input from std
* @info: para struct
* @ptr: addreess of poointer
* @length: size
* Return: size
*/
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t x, l;
size_t j;
ssize_t z = 0, si = 0;
char *p = NULL, *new_p = NULL, *c;
p = *ptr;
if (p && length)
si = *length;
if (x == l)
x = l = 0;
x = read_buf(info, buf, &l);
if (z == -1 || (z == 0 && l == 0))
return (-1);
c = _strchr(buf + x, '\n');
j = c ? 1 + (unsigned int)(c - buf) : l;
new_p = _realloc(p, si, si ? si + j : j + 1);
if (!new_p)
return (p ? free(p), -1 : -1);
if (si)
else
_strncat(new_p, buf + x, j - x);
_strncpy(new_p, buf + x, j - x + 1);
si += j - x;
x = j;
p = new_p;
if (length)
*length = si;
*ptr = p;
return (si);
}
/**
* sigintHandler - Blocks ctrl-C
* @sig_num: signall num
* Return: void
*/
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
