#include "apue.h"
#include <stdlib.h>
#include <pthread.h>

struct foo {
	int             f_count;
	pthread_mutex_t f_lock;
	/* ... more stuff here ... */

	int count;
};

struct foo *
foo_alloc(void) /* allocate the object */
{
	struct foo *fp;

	if ((fp = malloc(sizeof(struct foo))) != NULL) {
		fp->f_count = 1;
		if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
			free(fp);
			return(NULL);
		}
		/* ... continue initialization ... */
	}
	return(fp);
}

void
foo_hold(struct foo *fp) /* add a reference to the object */
{
	pthread_mutex_lock(&fp->f_lock);
	fp->f_count++;
	pthread_mutex_unlock(&fp->f_lock);
}

void
foo_rele(struct foo *fp) /* release a reference to the object */
{
	pthread_mutex_lock(&fp->f_lock);
	if (--fp->f_count == 0) { /* last reference */
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_destroy(&fp->f_lock);
		free(fp);
	} else {
		pthread_mutex_unlock(&fp->f_lock);
	}
}

struct foo *fptr;

void* thr_fn(void *arg)
{
	if(fptr)
	{
		foo_hold(fptr);
		fptr->count++;
		sleep(2);
		printf("count = %d\n",fptr->count);
	    foo_rele(fptr);
	}
	return (void *)1;
}

void cleanup(void *arg)
{
	if(arg)
	{
		foo_rele((struct foo *)arg);
	}
}

int main(void)
{
	fptr = foo_alloc();
	if(fptr==NULL)
		err_quit("can not allocate foo struct\n");

	pthread_t tid1,tid2;
	tid1 = pthread_create(&tid1,NULL,thr_fn,NULL);
	tid2 = pthread_create(&tid2,NULL,thr_fn,NULL);
	
	sleep(10);
	return 0;
}
