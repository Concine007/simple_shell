#include "shell.h"

/**
 * main - En tr y  po int
 * @argc: nu mbe r o f  arg u me nts pa sse d to the  pr og ram
 * @argv: a rgu m ents  vec to r
 * Return: A lw ay  sS U  CCESS
 */

int main(int argc, char **argv)
{
	if (argc == 1)
		prompt(argv);
	if (argc == 2)
		run_commands_from_file(argv[1], argv);
	return (EXIT_SUCCESS);
}
