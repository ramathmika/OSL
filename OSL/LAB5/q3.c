#include <pthread.h>
#include <stdio.h>
#include <math.h>

void* thread_code(void* param) {
	int *arr = (int *)param,i,j,flag,k=0,n;
	n = arr[1] - arr[0];
	int *prime = (int *)malloc(sizeof(int)*n);
	for(i=arr[0];i<=arr[1];i++){
		flag = 1;
		for(j=2;j<sqrt(i);j++){
			if(i%j==0){
				flag = 0;
				break;
			}
		}
		if(flag)
			prime[k++] = i;
	}
	return (void *)prime;
}

void main() {
	pthread_t thread;
	int a,b,i;
	printf("Enter the starting and ending numbers: ");
	scanf("%d %d",&a,&b);
	int arr[2], *prime;
	arr[0] = a;
	arr[1] = b;
	pthread_create(&thread,0,&thread_code,(void*)arr);
	pthread_join(thread,(void **)&prime);
	printf("\nPrime numbers from %d to %d are: \n",a,b);
	for(i=0;i<(b-a);i++)
		if(prime[i]!=0)
			printf("%d ",prime[i]);
	printf("\n");
}