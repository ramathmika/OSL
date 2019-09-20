#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
volatile int counter = 0;

void *count(void *param){
	int p = (int)param;
	for(int i=0;i<100;i++){
		pthread_mutex_lock(&mutex);
		counter++;
		printf("Count = %d Thread: %d\n",counter,p);
		pthread_mutex_unlock(&mutex);
	}
}

int main(){
	pthread_t thread1, thread2;
	pthread_mutex_init(&mutex,0);
	pthread_create(&thread1,0,count,(void*)1);
	pthread_create(&thread2,0,count,(void *)2);
	pthread_join(thread1,0);
	pthread_join(thread2,0);
	pthread_mutex_destroy(&mutex);
	return 0;
}