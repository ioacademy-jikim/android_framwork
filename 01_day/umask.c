#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd;
	umask(0);
	fd = open("aaa", O_CREAT| O_TRUNC | O_RDWR , 0666 );
	close(fd);
	return 0;
}
