#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid = fork();
	if (pid<0){
		printf("Fork failed.\n");
		exit(-1);
	}
	else if (pid==0){
		execl("./q1", NULL);
	}
	else{
		wait(NULL);
		printf("Child complete!\n");
		exit(0);
	}
}