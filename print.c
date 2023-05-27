#include "shell.h"

/**
 * _print - wri tes  a s trin g  in  th e s tandar output
 * @string: poi nte  r  to  stri ng
 * Return: no. byt e s w r i te n   or
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, _strlen(string)));
}
/**
 * _perror - a s tr in g  i n   t h e   s t a nd a r   error
 * @err: po in t e r  t o  s t r i ng
 * Return: n o .  b yt e s    w r ite n   o r
 */
int _perror(char *err)
{
	return (write(STDERR_FILENO, err, _strlen(err)));
}
