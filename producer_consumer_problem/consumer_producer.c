#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

//#include <>

int MUL=1;
int m,n=0;
int b[3]={0,0,0};
pthread_mutex_t lm, lb;
int count=0;


//helper functions

int not_full(){
	for(int j=0;j<3;j++)
	{
		if(b[j]==0)
			return j;
	} 
	return -1;
}

int not_empty(){
	for(int j=0;j<3;j++)
	{
		if(b[j]!=0)
			return j;
	} 
	return -1;
}

void* producer(void * data){
	int id= *(int *)data;
	int index;
	for(int i=1;i<=7;i++)
	{
		//get buffer lock lb
		pthread_mutex_lock(&lb);
		
		//check: if not full -produce(update buff) and print
		index=not_full();
		if(index!=-1)
		{
			b[index]=i;
			printf("         Producer %d produced %d \n", id, i);
		}
		else{
			--i;
		}
		//release lb 
		pthread_mutex_unlock(&lb);
	}
	++count;
	pthread_exit(NULL);
}

void* consumer(void * data){
	int id= *(int *)data;
	int index=-1;
	int p=0;
	while(count!=m)
	{
		p=0;
		//get buffer lock
		pthread_mutex_lock(&lb);
		
		//check: if not empty -consume and print
		index=not_empty();
		if(index!=-1)
		{
			printf("Consumer %d consumed %d \n", id, b[index]);
			//update buff
			p=b[index];
			b[index]=0;
			
			//get lm - update MUL - release lm
			pthread_mutex_lock(&lm);
			MUL=MUL*p;
			pthread_mutex_unlock(&lm);
		}
		//release lb
		pthread_mutex_unlock(&lb);		
	}
	pthread_exit(NULL);
}


int main(){
	printf("Enter number of producers: \n");
	scanf("%d",&m);
	printf("Enter number of consumers: \n");
	scanf("%d",&n);
	
	pthread_t p[m];
	pthread_t c[n];
	
	int *data;
	
	//create threads m and n
	for(int i=0;i<m;i++)
	{	
		data=&i;
		pthread_create(&p[i],NULL,producer,data);
	}
	for(int i=0;i<n;i++)
	{
		data=&i;
		pthread_create(&c[i],NULL,consumer,data);
	}
	
	//join threads
	for(int i=0;i<m;i++)
	{
		pthread_join(p[i],NULL);
	}
	for(int i=0;i<n;i++)
	{
		pthread_join(c[i],NULL);
	}
	
	printf("MUL= %d \n",MUL);
	pthread_exit(NULL);
	return 0;
}


