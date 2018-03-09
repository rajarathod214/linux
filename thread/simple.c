#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void *thread_function(void *arg);

char message[]="Hello Raja !!";

int main()
{
	int res;
	void *thread_result;
	pthread_t thread_1;

	//res=pthread_create(&thread_1,NULL,thread_function,(void *)message);
	res=pthread_create(&thread_1,NULL,thread_function,message);

	if(res != 0)
	{
		perror("Thread creation Failed !");
		exit(EXIT_FAILURE);
	}

	res = pthread_join(thread_1,&thread_result);

	if(res != 0)
	{
		perror("Thread join failed !");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined, it returned %s \n",(char *)thread_result);
	printf("Now message:%s\n",message);
	
	exit(EXIT_SUCCESS);
	
}

void *thread_function(void *arg)
{
	printf("Thread function is running: Argument %s \n",(char *)arg);
	sleep(2);
	strcpy(message,"Bye !!");
	pthread_exit("Thank you for the CPU time");
}
