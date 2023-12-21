/*this is myshell code. it is my system-programming hw3
if you have any question about this code, please email to 32197083@dankook.ac.kr*/
#include <stdio.h>						// 헤더 선언
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/wait.h>

struct selfCmd{
    char *cmd;
    char *info;
    bool (*func) (int argc, char *argv[]);
}

