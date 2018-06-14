#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd, ret;
	char buff[128];
	//mknod("binder", 0666|S_IFCHR, 10<<8 | 45);
	umask(0);
	fd = open("binder", O_RDWR|O_CREAT|O_TRUNC, 0666);
	close(fd);
	fd = open("binder", O_RDWR);
	unlink("binder");
	write( fd, "hello", 5 );
	lseek( fd, 0, SEEK_SET );
	ret = read( fd, buff, sizeof buff );
	buff[ret] = 0;
	printf("%s\n", buff );
	close(fd);

	return 0;
}




