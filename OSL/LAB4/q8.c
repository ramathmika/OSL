#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void main(){
	int fp = open("students.txt",O_RDWR);
	int ch=0,w=0,l=0;
	char c[1];
	while(read(fp,c,1)) {
		ch++;
		if(c[0] == '\n' || c[0] == '\0')
			l++;
		if(c[0] == '\n' || c[0] == '\0' || c[0] ==' ' || c[0] == '\t')
			w++;
	}
	printf("Characters: %d\nWords: %d\nLines: %d\n",ch,w,l);
}