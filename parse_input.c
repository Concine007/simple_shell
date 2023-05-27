#include "shell.h"

/**
 * tokenize - ta k e str in g  and  par se  it i n to   t ok en s
 * @line: st ri n g   t o  b e   t o ke n i ze d
 * Return: a r ra y   o f   s t r i n g s  o f   t o k e n s
 */
char **tokenize(char *line)
{
	int len = 0;
	int volume = 15;
	char *delim, *token, **tokens = malloc(volume * sizeof(char *));

	if (!tokens)
	{
		_perror("ERROR token malloc failed");
		exit(1);
	}

	delim = " \t\r\n";
	token = strtok(line, delim);

	while (token != NULL)
	{
		tokens[len] = token;
		len++;

		if (len >= volume)
		{
			volume = (int) (volume * 1.5);
			tokens = realloc(tokens, volume * sizeof(char *));
		}

		token = strtok(NULL, delim);
	}

	tokens[len] = NULL;
	return (tokens);
}

/**
 * read_line - re ad li ne  fr o m  s td i n
 * Return: s tr i ng s   re a d
 */
char *read_line()
{
	char *line = NULL;
	size_t buf = 0;

	if (getline(&line, &buf, stdin) == -1)
	{
		free(line);
		exit(1);
	}
	return (line);
}
