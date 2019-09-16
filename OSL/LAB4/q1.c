#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

void main(){
	int status;
	pid_t pid;
	pid = fork();
	if(pid<0){
		printf("Error. Child not created\n");
	}
	else if(pid == 0){
		printf("Child process!\n");
		exit(0);
	}
	else{
		wait(&status);
		printf("Child completed. Parent continues.\n");
	}
}