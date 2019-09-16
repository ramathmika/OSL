#include <pthread.h>
#include <stdio.h>

void* thread_code(void* param) {
	printf("In the thread code\n");
}

int main() {
	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, 0);
	pthread_join(thread,0);
	printf("In the main code\n");
}