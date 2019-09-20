#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define MAX_SIZE 100000

int buf[MAX_SIZE] , p , c;
sem_t mutex , full , empty;

void * produce( void * arg ){
	int val;
	while( 1 ){
		sem_getvalue( &full , &val );
		if( val >= 10 ) continue;
		sem_wait( &empty );
		//sem_wait( &mutex );
		printf("item produced is %d\n",(p+1));
		buf[p++] = p;
		//sem_post( &mutex );
		sem_post( &full );
	}
}

void * consume( void * arg ){
	while( 1 ){
		sem_wait( &full );
		//sem_wait( &mutex );
		printf("item consumed is %d\n",buf[c++]);
		sleep(1);
		//sem_post( &mutex );
		sem_post( &empty );
	}
}

int main(){
	p = 0 , c = 0;
	pthread_t tid1 , tid2;
	sem_init( &mutex , 0 , 1 );
	sem_init( &full , 0 , 0 );
	sem_init( &empty , 0 , 10 );
	pthread_create( &tid1 , NULL , produce , NULL );
	pthread_create( &tid2 , NULL , consume , NULL );
	pthread_join( tid1 , NULL );
	pthread_join( tid2 , NULL );
}