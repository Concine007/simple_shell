#include "shell.h"

/**
 * _free - f r ee   b uf f er   a r ray
 * @buf: po i nt  e r  to ar r  ay   of s t ri n  g s
 * Return: vo i d
 */
void _free(char **buf)
{
	int x = 0;

	if (buf)
	{
		for (x = 0; buf[x]; x++)
			free(buf[x]);
		free(buf);
	}
}
