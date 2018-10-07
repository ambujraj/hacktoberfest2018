#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


sem_t s[5];

void pick(int i){
		printf("\nPhil %d: Thinking...\n",i);
		sem_wait(&s[i]);
		printf("Phil %d: Picked chopstick %d...\n",i,i);
		sem_wait(&s[i+1]);
		printf("Phil %d: Picked chopstick %d...\n",i,i+1);
}

void put(int i){
		sem_post(&s[i]);
		printf("Phil %d: Put back chopstick %d...\n",i,i);
		sem_post(&s[i+1]);
		printf("Phil %d: Put back chopstick %d...\n",i,i+1);
}

void* phil(void* data){
	int i= *(int*)data;
	//while (1)
	 {
		//pick chopsticks
		pick(i);
		//eating
			printf("Phil %d: Started eating...\n",i);
			printf("Phil %d: Finished eating...\n",i);
		//put back chopsticks
		put(i);
	}
	pthread_exit(NULL);
}

void* last_phil(void* data){
	int i= *(int*)data;
	//while (1) 
	{
		//pick chopsticks
		printf("\nPhil %d: Thinking...\n",i);
		sem_wait(&s[0]);
		printf("Phil %d: Picked chopstick 0 ...\n",i);
		sem_wait(&s[i]);
		printf("Phil %d: Picked chopstick %d...\n",i,i);
		//eating
			printf("Phil %d: Started eating...\n",i);
			printf("Phil %d: Finished eating...\n",i);
		//put back chopsticks
		sem_post(&s[0]);
		printf("Phil %d: Put back chopstick 0 ...\n",i);
		sem_post(&s[i]);
		printf("Phil %d: Put back chopstick %d...\n",i,i);
	}
	pthread_exit(NULL);
}


int main(){
	int n;
	//initialise all semaphores
	sem_init(&s[0],0,1);
	sem_init(&s[1],0,1);
	sem_init(&s[2],0,1);
	sem_init(&s[3],0,1);
	sem_init(&s[4],0,1);
	
	printf("No. of philosophers: 5\n No. of chopsticks: 5\n");
	n=5;
	pthread_t t[n];
	int rv[n];
	//start first n-1 threads
	for(int i=0;i<n-1;i++)
	{
		rv[i]=pthread_create(&t[i],NULL,phil,&i);
		if(rv[i]){
			printf("Thread wasn't created.\n Error code:%x",rv[i]);
			exit(1);
		}
		
	}

	//start last thread
	int l=n-1;
	rv[l]=pthread_create(&t[l],NULL,last_phil,&l);
	if(rv[l])
	{
		printf("Thread wasn't created.\n Error code:%x",rv[l]);
		exit(1);
	}
	for(int i=0;i<n;i++)
		pthread_join(t[i], NULL);	// if wanted to get some return value from thread then NULL-> &retval and in thread use pthread_exit(value_to be_returned)
	
	pthread_exit(NULL);
	return 0;
}
