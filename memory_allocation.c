#include<stdio.h>
#include<mcheck.h>
#include<stdlib.h>

int main()
{
	int *ptr,i;

	mtrace();
	
	for(i=0;i<3;i++)
		ptr=malloc(100);

	calloc(200,10);
	
}
