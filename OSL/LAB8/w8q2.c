#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
int buf[10],f,r;
sem_t mutex,full,empty,wt,wrt;
int readcount,rval=10;
void *writer(void *arg)
{
	do{
		wait(wrt);
		printf("writing%d\n",++rval);
		sleep(1);
		signal(wrt);
		sleep(2);

	}while(1);
}
void *reader(void *arg)
{
	do{
		wait(mutex);
		readcount++;
		if(readcount==1)
			wait(wrt);
		signal(mutex);
		printf("reading%d\n",rval);
		sleep(1);
		wait(mutex);
		readcount--;
		if(readcount==0)
			signal(wrt);
		signal(mutex);
		sleep(2);
	}while(1);
}
int main()
{
	readcount=0;
	pthread_t thread[4];

	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,5);
	pthread_create(&thread[0],0,writer,0);
	pthread_create(&thread[2],0,writer,0);
	pthread_create(&thread[1],0,reader,0);

		
	pthread_create(&thread[3],0,reader,0);
	pthread_join(thread[0],0);
	pthread_join(thread[2],0);
	pthread_join(thread[1],0);
	pthread_join(thread[3],0);

}