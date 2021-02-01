#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main()
{
	int fd = open("/dev/mychar", O_RDWR) ;
	char buff[]= "Hello World"; // buffer pour ecrire
	char buff2[100];// buffer pour lire

	printf("\nOpening Driver\n");
	if(fd < 0) {
		perror("Cannot open device file...\n");
		return -1;
	}

	ioctl(fd, 42, NULL);
	write(fd,buff,strlen(buff));
	read(fd,buff2,strlen(buff2));

	close(fd);
	printf("\nClosing Driver\n");
	return 0;
}

