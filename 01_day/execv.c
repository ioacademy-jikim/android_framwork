#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	char* path = argv[0];
    char* args[] = { path, 0 };
	printf("before\n");
	execv(path, argv);
	printf("after\n");
	return 0;
}
