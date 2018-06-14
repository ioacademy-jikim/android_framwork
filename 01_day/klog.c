#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("__kmsg__", O_RDWR);
	write(fd, "hello world\n", 12);
	close(fd);
	return 0;
}
