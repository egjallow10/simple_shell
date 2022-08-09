#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define EXIT_BUILTIN 1
#define NON_BUILTIN 0

extern char **environ;

extern int errno;

/**
  * struct built_in - struct for matching commands to built in commands
  * @command: the string matching the command to execute
  * @built_cmd: the built in command to call if command matches
  * Description: Special built in commands for custom shell
  */
typedef struct built_in
{
	char *command;
	char (*built_cmd)(char **, char **);
} do_built;

/*buit in headers */
char exit_builtin(char **, char **);
char env_builtin(char **, char **);

/*headers for prompt*/
/* prompt */
int print_str(char *);
int builtin_finder(char **);

/*free header*/
void free_double(char **);

/* headers for the path*/
char **build_path(char *);
void print_dir(char *);
void print_env(char **);
char *_getenv(char *);
char *cut_env(char *);

/* headers for prompt*/
int print_str(char *);
int builtin_finder(char **);
#endif /*_SHELL_H_*/



