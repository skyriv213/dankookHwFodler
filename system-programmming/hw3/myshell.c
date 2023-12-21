/*this is my hw3.code is basic shell code. if you have any question for this code,please email to gn1007@dankook.ac.kr */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/wait.h>

int parsing(char* buf, char* delims, char* tokens[], int maxTokens){
    int cnt = 0;
    char* t;
    t = strtok(buf, delims); // split by delimiter

    while (t != NULL && cnt < maxTokens){
        tokens[cnt++] = t;
        t = strtok(NULL, delims);
    }
    tokens[cnt] = NULL;
    return cnt;
}

bool start(char* line){
    char delims[] = " \n";
    char* tokens[128];
    int t_cnt;
    int status;
    pid_t pid;

    t_cnt = parsing(line, delims, tokens, sizeof(tokens) / sizeof(char*));
    if (t_cnt == 0){
        return true;
    }

    if (strcmp(tokens[0], "exit")==0){
	return false;
	}
    int fd;
	int i;
    int j;
    for (i = 0; i < t_cnt; ++i) {
        if (strcmp(tokens[i], ">") == 0) {
            char* filename = tokens[i + 1];

            tokens[i] = NULL;

            fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

            dup2(fd, 1);
            close(fd);
	
            for (j = i; j < t_cnt - 2; ++j) {
                tokens[j] = tokens[j + 2];
            }

            t_cnt -= 2;

            break;
        }
    }

    if ((pid = fork()) < 0){
        perror("fork error");
        exit(-1);
    }
    else if (pid == 0){
        execvp(tokens[0], tokens);
	perror("execvp error");
	exit(-1);
    }
    waitpid(pid, &status, 0);
    return true;
}

int main(void){
    char line[128];
    while (1){

        printf("%s : myshell $ ", getcwd(NULL, 0));
        fgets(line, sizeof(line) - 1, stdin);
        if (!start(line)){
            break;
        }
    }
    return 0;
}
 
