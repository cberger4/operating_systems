// C program to demonstrate working of Semaphores 
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

sem_t mutex; 

void* thread1(void* arg) 
{ 
	//wait 
	sem_wait(&mutex); 
	printf("\nThis should happen second.\n"); 
} 

void* thread2(void* arg) 
{ 
	//wait 
	sem_wait(&mutex); 
	printf("\nThis should happen first.\n");   

} 

int main() 
{ 
	sem_init(&mutex, 0, 0); 
	pthread_t t1,t2; 
	pthread_create(&t1,NULL,thread1,NULL); 
	sleep(2); 
	pthread_create(&t2,NULL,thread2,NULL); 
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	sem_destroy(&mutex); 
	return 0; 
} 