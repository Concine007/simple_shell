#include "shell.h"

/**
* _erratoi - Converts str to an int
* @s: string
* Return: 0
*/
int _erratoi(char *s)
{
int x = 0;
unsigned long int r = 0;

if (*s == '+')
s++;
for (x = 0; s[x] != '\0'; x++)
{
if (s[x] >= '0' && s[x] <= '9')
{
r *= 10;
r += (s[x] - '0');
if (r > INT_MAX)
return (-1);
}
else
return (-1);
}
return (r);
}
/**
* print_error - Prints an error message
* @info: the parameter
* @estr: string error
* Return: 0
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}
/**
* print_d - function prints decimal
* @input: the input number
* @fd: filedescriptor
* Return: number of characters printed
*/
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int x, c = 0;
unsigned int _a_, cu;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_a_ = -input;
__putchar('-');
c++;
}
else
_a_ = input;
cu = _a_;
for (x = 1000000000; x > 1; x /= 10)
{
if (_a_ / x)
{
__putchar('0' + cu / x);
c++;
}
cu %= x;
}
__putchar('0' + cu);
c++;
return (c);
}
/**
* convert_number - Converter fun
* @num: number
* @base: base
* @flags: flag
* Return: string
*/
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

/*if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}*/
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" :
"0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);
if (sign)
*--ptr = sign;
return (ptr);
}
/**
* remove_comments - Replaces # with 0
* @buf: address
* Return: 0;
*/
void remove_comments(char *buf)
{
int x;

for (x = 0; buf[x] != '\0'; x++)
if (buf[x] == '#' && (!x || buf[x - 1] == ' '))
{
buf[x] = '\0';
break;
}
}
