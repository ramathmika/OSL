#include <stdio.h>
#include <fcntl.h>
#include <string.h>
void main(){
	int fp = creat("students.txt",O_RDWR);
	char array[100] = "Message";
	write(fp,array,strlen(array));
}