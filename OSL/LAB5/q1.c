#include <pthread.h>
#include <stdio.h>


void* thread_code(void* param){
	int n= (int)param, i;
	int *fib = (int *)malloc(sizeof(n)*n);
	//printf("%d\n",n);
	printf("%d\n",n);
	fib[0] = 0;
	fib[1] = 1;
	for(i=2;i<n;i++)
		fib[i] = fib[i-1] + fib[i-2];
	return (void *)fib;
}

void main(){
	pthread_t thread;
	int n,i;
	printf("Enter the number: \n");
	scanf("%d",&n);
	int *fib;
	pthread_create(&thread,0,&thread_code,(void *)n);
	pthread_join(thread,(void **)&fib);
	printf("Fibonacci series till %d is: \n",n);
	for(i=0;i<n;i++)
		printf("%d \n",fib[i]);
	printf("\n");
}