
#include "apue.h"
#include <stdlib.h>
#include <pthread.h>

int i = 0;
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_mutex_t mutex;

void* thr_fn(void *arg)
{
	pthread_t pt;
	pid_t pid;
	pt = pthread_self();
	pid = getpid();
	while(i<200)
	{
		//sleep(2);
		pthread_mutex_lock(&mutex1);
		pthread_mutex_lock(&mutex);
		pthread_mutex_unlock(&mutex1);
		
		printf("count = %d,thread_id = %u pid = %u\n",i++,(unsigned int)pt,pid);
		
		pthread_mutex_lock(&mutex1);
		pthread_mutex_lock(&mutex);
		pthread_mutex_unlock(&mutex1);
	}
	return (void *)1;
}

void* thr_fn2(void *arg)
{
	pthread_t pt;
	pid_t pid;
	pt = pthread_self();
	pid = getpid();
	while(i<200)
	{
		//sleep(2);
		pthread_mutex_lock(&mutex2);
		pthread_mutex_unlock(&mutex1);
		printf("count = %d,thread_id = %u pid = %u\n",i++,(unsigned int)pt,pid);
		//pthread_mutex_unlock(&mutex1);
	}
	return (void *)1;
}

int main(void)
{
	pthread_t tid1,tid2;
	if(pthread_mutex_init(&mutex1,NULL)!=0)
	{
		err_sys("can not create a mutex");
		}
		
	if(pthread_mutex_init(&mutex2,NULL)!=0)
	{
		err_sys("can not create a mutex");
		}
		
	if(pthread_mutex_init(&mutex,NULL)!=0)
	{
		err_sys("can not create a mutex");
		}
	tid1 = pthread_create(&tid1,NULL,thr_fn,NULL);
	tid2 = pthread_create(&tid2,NULL,thr_fn,NULL);
	sleep(10);//防止主线程退出
	
	return 0;
}
