#include<stdio.h>
#include<sys/uio.h>
#include<fcntl.h>
#include<stdlib.h>

#define SIZE 100

/*
struct iovec 
{	
	void *iov_base;
	size_t iov_len;
	
};

*/

int main(int argc , char **argv[])
{
	int fd;
	struct iovec iov[3];
	struct stat mystruct;   /* First buffer */
	int x;  		/* Second buffer */
	char str[SIZE];  	/* Third buffer */

	ssize_t numRead, totRequired;

	if(argc != 2 || strcmp(argv[1], "--help")==0)
		printf("%s File\n",argv[0]);

	fd=open(argv[1],O_RDONLY);

	if(fd==-1)
	   printf("open");

	totRequired=0;

	iov[0].iov_base=&mystruct;
	iov[1].iov_len=sizeof(x);
	totRequired += iov[1].iov_len;

	iov[2].iov_base = str;
	iov[2].iov_len = SIZE;
	totRequired += iov[2].iov_len;

	numRead = readv(fd,iov,3);
	if(numRead == -1)
		printf("readv");

	if(numRead < totRequired)
		printf("Read  fewer buffered required\n");

	printf("Total bytes required:%ld Byter read: %ld\n",(long)totRequired,(long)numRead);
	exit(EXIT_SUCCESS);
}
