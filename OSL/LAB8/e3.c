#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t semaphore;
int i=0;

void *func1(void *param){
	printf("Thread 1\n");
//	sem_post(&semaphore);
	 while(i<100){
	 	printf("Thread 1: %d\n",i);
	 	i++;
	 }
	
}

void *func2(void *param){
//	sem_wait(&semaphore);
	printf("Thread 2\n");
	while(i>-100){
	 	printf("Thread 2: %d\n",i);
	 	i--;
	 }
}

int main(){
	pthread_t threads[2];
//	sem_init(&semaphore,0,1);
	pthread_create(&threads[0],0,func1,0);
	pthread_create(&threads[1],0,func2,0);
	pthread_join(threads[0],0);
	pthread_join(threads[1],0);
//	sem_destroy(&semaphore);
}