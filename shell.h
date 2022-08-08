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

