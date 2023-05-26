#include "shell.h"

/**
* is_cmd - de ter min es if a  fil e is  an  exe cu ta bl e com m an d
* @info: th e in fo st ru ct
* @path: pa th t o th e fi le
* Return: 1 i f t ru e, 0 oth er wi se
*/
int is_cmd(info_t *info, char *path)
{
struct stat st;
(void)info;
if (!path || stat(path, &st))
return (0);
if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}
/**
* dup_chars - du pl ic a tes cha r act ers
* @pathstr: t he Pa th str in g
* @start: st ar ti ng  ind ex
* @stop: st op p i ng  ind ex
* Return: p oin ter  to  ne w bu ff er
*/
char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[1024];
int x = 0, z = 0;
for (z = 0, x = start; x < stop; x++)
if (pathstr[x] != ':')
buf[z++] = pathstr[x];
buf[z] = 0;
return (buf);
}
/**
* find_path - fi nds t hi s  cm d  in   t he  P AT H  str i ng
* @info: t he i nf o  st ru ct
* @pathstr: t he Pa th str in g
* @cmd: t he  cm d  t o fi n d
* Return: fu l l  p at h   o f   c m d   i f  f o und  or   N U L
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
int x = 0, c = 0;
char *path;
if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[x] || pathstr[x] == ':')
{
path = dup_chars(pathstr, c, x);
if (!*path)
_strcat(path, cmd);
else
{
}
_strcat(path, "/");
_strcat(path, cmd);
if (is_cmd(info, path))
return (path);
if (!pathstr[x])
break;
c = x;
}
x++;
}
return (NULL);
}
