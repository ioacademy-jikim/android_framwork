#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


void foo( char *dname )
{
	DIR *dp;
	struct dirent *p;
	struct stat buf;
	chdir(dname);
	dp = opendir(".");
	while( p = readdir(dp))
	{
		int dfd = dirfd(dp);
    	int fd = openat(dfd, "uevent", O_WRONLY);
        write(fd, "add\n", 4);
        close(fd);
		lstat(p->d_name, &buf);
		if( S_ISDIR( buf.st_mode ) )
		{
			if( strcmp(p->d_name,".") && strcmp(p->d_name,"..") )
				foo( p->d_name );
		}
	}
	closedir(dp);
	chdir("..");
}

int main()
{
	foo(".");
	return 0;
}
