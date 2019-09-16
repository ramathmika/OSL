#include <sys/types.h>
#include <stdio.h>

void main(){
	pid_t pid;
	int cpid, ppid;
	pid = fork();
	if(pid<0){
		printf("Error\n");
		exit(-1);
	}
	else if (pid == 0){
		cpid = getpid();
		ppid = getppid();
		printf("\nChild Process\nProcess ID: %d\nParent PID: %d\n",cpid,ppid);
	}
	else {
		cpid = getpid();
		printf("\nParent Process\nProcess PID: %d\nChild PID: %d\n",cpid,(int)pid);
	}
}