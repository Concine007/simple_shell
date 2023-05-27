#include "shell.h"

/**
 * my_exit - ex it
 */
void my_exit(void)
{
	exit(EXIT_SUCCESS);
}
/**
 * my_exit_status - ex it
 * @args: arr ay   of   s t r in g s   o f   a r gu m e n ts
 * Return: vo id
 */
void my_exit_status(char **args)
{
	int state = atoi(args[1]);
	free(args);
	exit(state);
}

/**
 * _cd - cvha n ge s  t h e  c ur re n t  w o r ki n g  d i re  c t ory
 * @args: A n arr ay  of  stri ng s co nt aini ng  th e  de s ti nat io ny
 * Return: vo id
 */
void _cd(char **args)
{
	char *home;

	if (!args[0])
		_perror("cd: missing argument\n");
	else if (!args[1])
	{
		home = getenv("HOME");
		if (chdir(home) != 0)
			_perror("cd: No such file or directory\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
			_perror("cd: No such file or directory\n");
	}
}

/**
 * env_shell - p ri nt  th e  c ur re n t env ir o nmen t
 * Return: No th i ng
 */
void env_shell(void)
{
	int x = 0;

	while (environ[x] != NULL)
	{
		_print(environ[x]);
		_print("\n");
		x++;
	}
}
