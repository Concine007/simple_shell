#include "shell.h"

/**
 * set_env - fu n cti on   to s e t  an  e nv ir o n me n t  v a riab le
 * @name: n am e  o f   t h e  e n v  i r o n me nt   v a r i a ble
 * @value: va lu e   to   b e   as s igne d  t o   the  en v ir onme nt
 * Return: 0  on   s u c c e  s s ,  - 1   o  n  f  ai l  u re
 */
int set_env(char *name, char *value)
{
	char *env_var;
	int len;

	len = strlen(name) + strlen(value) + 2;
	env_var = malloc(len);
	if (env_var == NULL)
		return (-1);
	snprintf(env_var, len, "%s=%s", name, value);
	if (putenv(env_var) != 0)
		return (-1);
	return (0);
}

/**
 * unset_env - function to unset an environment variable
 * @name: name of the environment variable
 * Return: 0 on success, -1 on failure
 */
int unset_env(char *name)
{
	if (unsetenv(name) != 0)
		return (-1);
	return (0);
}
