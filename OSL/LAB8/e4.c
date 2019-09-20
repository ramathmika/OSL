#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int buf[5],f=-1,r=-1;

sem_t mutex,full,empty;

void *produce(void *arg){
	int i;
	for(i=0;i<10;i++){
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("\nProduced item is %d\n",i+1);
		buf[(++r)%5] = i+1;
//		sleep(1);
		sem_post(&mutex);
		sem_post(&full);
		int FULL;
		sem_getvalue(&full,&FULL);
		printf("Producer: Full: %d\n",FULL);
//		sleep(1);
	}
}

void *consume(void *arg){
	int item,i;
	for(i=0;i<10;i++){
			
			sem_wait(&full);
			sem_wait(&mutex);
//			sleep(1);
			item = buf[(++f)%5];

			printf("\nConsumed item is %d\n",item);
//			sleep(1);

			int FULL;			
			sem_getvalue(&full,&FULL);
			printf("Consumer: Full: %d\n",FULL);
			sem_post(&mutex);
			sem_post(&empty);

			int val;

			// sem_getvalue(&wt,&val);
			// if(val<10)
			// 	sem_post(wrt);

		}
}

int main() {
	pthread_t tid1,tid2;
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,5);
	pthread_create(&tid1,NULL,produce,NULL);
	pthread_create(&tid2,NULL,consume,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}