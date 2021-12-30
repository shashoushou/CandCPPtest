#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <termios.h>
#include <sys/signal.h>
#include <sys/ioctl.h>
#include <stdarg.h>
#include <asm/types.h>
#include <errno.h>

#define DELAY   10000
#define true 1
#define false 0
#define BRATE	    	B115200
#define RS485_1		"/dev/ttyS3"
#define RS485_2 	"/dev/ttyS4"

static struct termios oldtio;

int opentty(char *dev)
{
	int fd;
	struct termios newtio;

	if((fd = open(dev , O_RDWR | O_NOCTTY)) < 0) {
		perror("open");
		exit(-1);
	}
	if(tcgetattr(fd, &oldtio) < 0) {
		perror("tcgetattr");
		exit(1);
	}
	cfmakeraw(&newtio);
	newtio.c_cflag |= (BRATE | CS8 | CLOCAL | CREAD);
	newtio.c_cflag &= ~CSTOPB; //1stop
	newtio.c_cflag &= ~PARENB; 
	newtio.c_iflag &= ~INPCK; 

	newtio.c_iflag |= (IGNPAR | INPCK);
	newtio.c_iflag &= ~( IXON | IXOFF);

	newtio.c_lflag = 0;
	newtio.c_lflag &= ~( ECHO | ICANON | ISIG);

	newtio.c_oflag = 0;
	newtio.c_oflag &= ~( OPOST );

	newtio.c_cc[VMIN] = 1; // 2 sec
	newtio.c_cc[VTIME] = 20;
	if(tcsetattr(fd, TCSANOW, &newtio) < 0)
	{
		perror("tcsetattr");
		exit(1);
	}
	tcdrain(fd);
	if(fd == -1){
		perror("open: ");		
	} else {
		printf("open %s device \n", dev);
	}
	return fd;

}


void closetty(int fd)
{
	tcsetattr(fd, TCSANOW, &oldtio);
	if(close(fd) < 0){
		perror("close");
		exit(-1);
	}
}

void *send(void *fd)
{
	printf("%s\n...", __func__);
	int c;
	char buf[10];

	c = 0;
	do {
		memset(buf, 0, 10);
		read(STDIN_FILENO, buf, 10);
		if(strlen(buf) > 0) {
			if(write(*(int *)fd, buf, strlen(buf)) == -1)
				perror("write");
		}
	} while(1);
}

void *receive(void *fd)
{
	int r;
	int i;
	char buf[10];
	do {
		memset(buf, 0, 10);
		r = read(*(int *)fd, buf, 10);
		if(r == -1)
			perror("read");
		printf("receive: ");
		for( i = 0; i < 10; i++)
			if(strlen(buf) >0)
				printf("%x", buf[i]);

		printf("\n");
		//            write(STDOUT_FILENO, buf, strlen(buf));
	} while(1);
}

int main(int argc, char **argv)
{

	system("clear");
	printf("---------------------------------\n");
	int fd;
	int dirfd = -1;
	int option;
	pthread_t thread1, thread2;
	int ts;
	char buf[4];
	char trigger_nune[] = "none";

	while((option = getopt(argc, argv, "d:s:")) >0) {
		switch(option) {
			case 'd':
				if(atoi(optarg) == 1){
					fd = opentty(RS485_1);
					dirfd = open("/sys/class/leds/rs485_d1/brightness", O_WRONLY);
					if(dirfd == -1) {
						perror("open: ");		
					}
					break;
				} else if(atoi(optarg) == 2) {
					fd = opentty(RS485_2);
					dirfd = open("/sys/class/leds/rs485_d2/brightness", O_WRONLY);
					if(dirfd == -1) {
						perror("open: ");		
					}
					break;
				}
			case 's':
				if(atoi(optarg))
					ts = 1; //send
				else 
					ts = 0; //receive
				break;
			case '?':
			case ':':
			default :
				break;

		}
	}  
	if(!ts){
		write(dirfd, "0", 1);
		printf("receive:\n");
		pthread_create(&thread1, NULL, &receive, &fd);
	}
	else {
		write(dirfd, "1", 1);
		printf("send:\n");
		pthread_create(&thread2, NULL, &send, &fd);
	}
	while(1){
	}
	closetty(fd);
	close(dirfd);
	return 0;        
}

