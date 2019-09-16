# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/msg.h>

struct my_msg_st{
	long int my_msg_type;
	char some_text[BUFSIZ];
};

int main()
{
	int running = 1, msgid, flag;
	struct my_msg_st some_data;
	long int msg_to_receive = 0;
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if(msgid == -1){
		fprintf(stderr, "msggett failed with error:%d\n",errno);
		exit(EXIT_FAILURE);
	}
	flag = 1;
	if(msgrcv(msgid,(void*)&some_data,BUFSIZ,msg_to_receive,0) == -1){
		fprintf(stderr, "msgrcv failed with error:%d\n",errno);
		exit(EXIT_FAILURE);
	}
	int n = strlen(some_data.some_text)-1;
	for(int i=0;i<n/2;i++)
		if(some_data.some_text[i] != some_data.some_text[n-i-1]){
			flag = 0;
			break;
		}
	if (flag)
		printf("Palindrome.\n");
	else
		printf("Not Palindrome.\n");
	
	exit(EXIT_SUCCESS);

}