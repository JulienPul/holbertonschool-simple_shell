#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;
void execute_command(char **argv, char *program_name);
char **tokenize_line(char *line);

#endif /* MAIN_H */
