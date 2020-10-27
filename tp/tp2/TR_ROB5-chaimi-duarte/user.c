/*
 * Includes
 */
#include <fcntl.h>
#include <sys/ioctl.h>

int main(void) {
    int filedesc = open("/dev/mychar", O_RDWR);
    if(filedesc<0) {
        printf("Task create: %s", strerror(filedesc));
    }
    write
    return 0;
}