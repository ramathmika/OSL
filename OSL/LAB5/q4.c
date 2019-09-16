#include <pthread.h>
#include <stdio.h>

void* even_sum(void* param){
	int *arr = (int *)param,sum=0,i,n;
	n = arr[0];
	//printf("%d\n",n);
	for(i=1;i<=n;i++)
		if(arr[i]%2==0)
			sum += arr[i];
	return (void *)sum;
}

void* odd_sum(void* param){
	int *arr = (int *)param,sum=0,i,n;
	n = arr[0];
	//printf("%d\n",n);
	for(i=1;i<=n;i++)
		if(arr[i]%2!=0)
			sum += arr[i];
	return (void *)sum;
}

void main(){
	int n,i,esum,osum;
	pthread_t thread;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	arr[0] = n;
	printf("Enter elements: ");
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	pthread_create(&thread, 0, &even_sum, (void *)arr);
	pthread_join(thread,(void **)&esum);
	pthread_create(&thread, 0, &odd_sum, (void *)arr);
	pthread_join(thread,(void **)&osum);
	printf("Sum of even elements: %d\nSum of odd elements %d\n",esum,osum);
}