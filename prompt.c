#include "shell.h"

/**
 * prompt - fu n cti on  t o   in t er  pr et   c om ma  n ds  wi th arg
 * @argv: a r gu m e nt s  ve ct o r
 * Return: vo id
 */
void prompt(char **argv __attribute__((unused)))
{
	char line[INPUT_LEN];
	int terminal = isatty(STDIN_FILENO);

	while (1)
	{
		if (terminal)
			_print(PROMPT);
		if (fgets(line, INPUT_LEN, stdin) == NULL)
			break;
		file_prompt(line, argv);
	}
}
