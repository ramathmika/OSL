#include <pthread.h>
#include <stdio.h>

void* thread_code(void* param){
	int *arr = (int *)param;
	int sum = arr[0] + arr[1];
	return (void *)sum;
}

void main(){
	pthread_t thread;
	int a,b,sum;
	printf("Enter two non-negative numbers: ");
	scanf("%d %d",&a,&b);
	int *arr = (int *)malloc(sizeof(int)*2);
	arr[0] = a;
	arr[1] = b;
	pthread_create(&thread,0,&thread_code,(void *)arr);
	pthread_join(thread,(void **)&sum);
	printf("Sum is: %d\n",sum);
}