#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#define PROMPT "#cisfun$ "
#define MAX_CMD 10
#define MAX_PATH_LEN 1024
#define INPUT_LEN 1024
#define MAX_LINE_LENGTH 1024

extern char **environ;

/**
 * struct builtin - s tr u c t  t o   h o ld   b ui l t - i n   c o mmand
 * @name: na m e  o f   t he  b ui l t - in   c omm and
 * @func: po in t e r  t   o  t h e  f u nc t i o n  th  at  i mp  l e m e
 */
typedef struct builtin
{
	char *name;
	void (*func)(char **args);
} builtin_t;

extern builtin_t builtins[];

void my_exit(void);
void my_exit_status(char **args);
void _cd(char **args);
void env_shell(void);

void prompt(char **argv);
void execute_command(char **args, char *arg);


char **tokenize(char *line);
char *read_line();


int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _puts(char *str);
char *_strtok(char *s, char d);


int _print(char *string);
int _perror(char *err);


void _free(char **buf);
char *search_path(char *filename);

int set_env(char *name, char *value);
int unset_env(char *name);


void run_commands_from_file(const char *filename, char **argv);
void file_prompt(char *line, char **argv);


#endif
