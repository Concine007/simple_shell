#include "shell.h"

/**
 * run_commands_from_file - exe cut e  c omm a nd  f ro m  a   fi  le
 * @filename: p oi n t er t o  s t r i ng  o f  f i l e  n a me
 * @argv: @argv: a r ra y   st r i n g  o f  a r g u m ents
 * Return: vo id
 */
void run_commands_from_file(const char *filename, char **argv)
{
	char line[MAX_LINE_LENGTH];
	FILE *fp = fopen(filename, "r");

	if (!fp)
	{
		_perror(argv[0]);
		_perror(": 0: Can't open");
		_perror("\n");
		exit(127);
	}

	while (fgets(line, MAX_LINE_LENGTH, fp) != NULL)
	{
		file_prompt(line, argv);
	}

	fclose(fp);
}

/**
 * file_prompt - fu nc t io n   t o   i nte r p r e t  c o m m a n ds
 * @line: c om m an d   l i n e
 * @argv: ar  ra y   s t r i ng   o f   a r g um e n t s
 * Return: vo id
 */
void file_prompt(char *line, char **argv)
{
	char **tokens, previous, *l, *cmt;
	int q;

	previous = '\0';
	cmt = NULL;
	q = 0;
	l = line;
	while (*l != '\0')
	{
		if (*l == '"' && previous != '\\')
			q = !q;
		else if (*l == '#' && previous != '\\' && !q)
		{
			if (previous == ' ')
			{
				cmt = l;
				break;
			}
		}
		previous = *l;
		l++;
	}
	if (cmt != NULL)
		*cmt = '\0';
	line[strcspn(line, "\n")] = '\0';
	tokens = tokenize(line);
	if (tokens[0] != NULL)
	{
		if (strcmp(tokens[0], "exit") == 0)
		{
			if (tokens[1] != NULL)
			{
				my_exit_status(tokens);
			}
			free(tokens);
			my_exit();
		}
		execute_command(tokens, argv[0]);
	}
	free(tokens);
}
