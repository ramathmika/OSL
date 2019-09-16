#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF
int main(){
	int pipe_fd,res,open_mode=O_RDONLY;
	char buffer[BUFFER_SIZE + 1];
	int bytes_read = 0;
	memset(buffer,'\0',sizeof(buffer));
	printf("Process %d opening FIFO O_RDONLY\n",getpid());
	pipe_fd = open(FIFO_NAME,open_mode);
	printf("Process %d result %d\n",getpid(),pipe_fd);
	int i = 0;
	if(pipe_fd != -1){
		while(i<4){
			res = read(pipe_fd,buffer[0],1);
			printf("%s\n",buffer);
			i++;
		}
		(void)close(pipe_fd);
	}
	else {
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished, %d bytes read\n",getpid(),bytes_read);
	exit(EXIT_SUCCESS);
}