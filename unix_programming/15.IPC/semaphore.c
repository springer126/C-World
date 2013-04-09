#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

#define MAX 100
int stack[MAX][2];
int size;

void* ReadData1(void *p)
{
	FILE *pf = fopen("1.dat","r");
	while(!feof(pf))
	{
		fscanf(pf,"%d%d",&stack[size][0],&stack[size][1]);
		printf("Read From 1.dat: %d %d\n",stack[size][0],stack[size][1]);
		size++;
		sem_post(&sem);
	}	
	fclose(pf);
}

void* ReadData2(void *p)
{
	FILE *pf = fopen("2.dat","r");
	while(!feof(pf))
	{
		fscanf(pf,"%d%d",&stack[size][0],&stack[size][1]);
		printf("Read From 2.dat: %d %d\n",stack[size][0],stack[size][1]);
		size++;
		sem_post(&sem);
	}	
	fclose(pf);
}

void* HandleData1(void *p)
{
	while(1)
	{
		sem_wait(&sem);
		printf("Handle Multiply: %d * %d = %d\n",stack[size][0],stack[size][1],stack[size][0]*stack[size][1]);
		size--;
	}
}

void* HandleData2(void *p)
{
	while(1)
	{
		sem_wait(&sem);
		printf("Handle Add: %d + %d = %d\n",stack[size][0],stack[size][1],stack[size][0]+stack[size][1]);
		size--;
	}
}

int main()
{
	pthread_t t1,t2,t3,t4;
	sem_init(&sem,0,0);
	
	pthread_create(&t3,NULL,HandleData1,NULL);
	pthread_create(&t4,NULL,HandleData2,NULL);
	pthread_create(&t1,NULL,ReadData1,NULL);
	pthread_create(&t2,NULL,ReadData2,NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
