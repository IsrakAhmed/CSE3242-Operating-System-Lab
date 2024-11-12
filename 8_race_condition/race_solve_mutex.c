#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int x = 0;
pthread_mutex_t key;

void addition(){
	pthread_mutex_lock(&key);
	printf("Start Addition\n");
	for(int i=0;i<10;i++){
		x = x+1;
		printf("%d: Addition= x+1: %d\n",i,x); 
	}
	pthread_mutex_unlock(&key);

}

void subtraction(){
	pthread_mutex_lock(&key);
	printf("Start Subtraction\n");
	for(int i=0;i<10;i++){
		x = x-1;
		printf("%d: Subtraction= x-1: %d\n",i,x); 
	}
	pthread_mutex_unlock(&key);
}

void main(){
	
	pthread_t thread1, thread2;
	
	pthread_create(&thread1, NULL, (void *)addition, NULL);
	pthread_create(&thread2, NULL, (void *)subtraction, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2,NULL);
}