#include "shell.h"

/**
 * execute_command - fu ncti o n  t o  exe c u te  com m an d
 * @args: ar gum en t s
 * @arg: po in t e r  t o   t h e  n a m e   o f  th e   pr o g r am
 * Return: 0  o n   s uc  ce ss   a  n d  1   o n   f a il u  re
 */
void execute_command(char **args, char *arg)
{
	int state;
	pid_t pid;

	if (_strcmp(args[0], "cd") == 0)
	{
		_cd(args);
		return;
	}
	else if (strcmp(args[0], "env") == 0)
	{
		env_shell();
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
		if (errno == ENOENT)
		{
			_perror(arg);
			_perror(": No such file or directory\n");
			exit(127);
		}
		else
		{
			_perror("Command not found.\n");
			exit(127);
		}

	}
	else if (pid > 0)
		waitpid(pid, &state, WUNTRACED);
	else if (pid < 0)
		_perror("failed to fork\n");
}
/**
 * search_path - s e ar  ch  fo r  c om m a n d   p a t h
 * @filename: poi nt e r  t o   st ri n g   to   s e a rc h   f or
 * Return: p oi n te r   to   s t r in g  o f  p a th
 */
char *search_path(char *filename)
{
	char *path, *path_env, *full_path;

	if (filename[0] == '/')
	{
		if (access(filename, F_OK) == 0)
			return (realpath(filename, NULL));
		else
			return (NULL);
	}

	path_env = malloc(MAX_PATH_LEN * sizeof(char));
	snprintf(path_env, MAX_PATH_LEN, "/bin:%s", getenv("PATH"));
	path = strtok(path_env, ":");
	full_path = malloc(MAX_PATH_LEN * sizeof(char));

	while (path != NULL)
	{
		snprintf(full_path, MAX_PATH_LEN, "%s/%s", path, filename);
		if (access(full_path, F_OK) == 0)
		{
			free(path_env);
			return (realpath(full_path, NULL));
		}
		path = strtok(NULL, ":");
	}

	free(path_env);
	free(full_path);
	return (NULL);
}
