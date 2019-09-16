#include <stdio.h>
#include <fcntl.h>
#include <string.h>
void main(){
	int fp = creat("file2.txt",O_RDWR);
	int fp2 = open("students.txt",O_RDWR);
	char buf[100];
	read(fp2,buf,sizeof(buf));
	write(fp,buf,strlen(buf));
}