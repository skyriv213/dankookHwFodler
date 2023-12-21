#include <stdio.h>
#include <sys/types.h>>
#include <unistd.h>
#define MAXARGS 128
#define MAXLINE 1024
// void main();
void eval(char *cmdline);
int builtin_command(char **argv);
int parseline(char *buf, char **argv);

