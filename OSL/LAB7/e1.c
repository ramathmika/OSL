#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n, fd[2];
	char buf[1025], *data="Hello... This is sample data.";
	pipe(fd);
	write(fd[1],data,strlen(data));
	if((n=read(fd[0],buf,1024))>=0) {
		buf[n] = 0;
		printf("Read %d bytes from the pipe: \"%s\"\n",n,buf);
	}
	else
		perror("read");
	exit(0);
}