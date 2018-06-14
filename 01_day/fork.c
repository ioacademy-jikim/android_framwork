#if 1
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	while( waitpid(-1,0,WNOHANG) > 0 )
		;
}

int main()
{
	int i,j;
	signal( SIGCHLD, my_sig );
	for(i=0; i<5; i++ )
	{
		if( fork() == 0 )
		{
			for(j=0; j<i+1; j++ )
			{
				printf("\t\t\t\tchild\n");
				sleep(1);
			}
			exit(0);
		}
	}
	for(;;)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;  
}
#endif
#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	while( wait(0) > 0 )
		;
}

int main()
{
	int i,j;
	signal( SIGCHLD, my_sig );
	for(i=0; i<5; i++ )
	{
		if( fork() == 0 )
		{
			for(j=0; j<i+1; j++ )
			{
				printf("\t\t\t\tchild\n");
				sleep(1);
			}
			exit(0);
		}
	}
	for(;;)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;  
}
#endif
#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	while( wait(0) > 0 )
		;
}

int main()
{
	int i,j;
	signal( SIGCHLD, my_sig );
	for(i=0; i<100; i++ )
	{
		if( fork() == 0 )
		{
			for(j=0; j<3; j++ )
			{
				printf("\t\t\t\tchild\n");
				sleep(1);
			}
			exit(0);
		}
	}
	for(;;)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;  
}
#endif
#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	wait(0);
}

int main()
{
	int i,j;
	signal( SIGCHLD, my_sig );
	for(i=0; i<100; i++ )
	{
		if( fork() == 0 )
		{
			for(j=0; j<3; j++ )
			{
				printf("\t\t\t\tchild\n");
				sleep(1);
			}
			exit(0);
		}
	}
	for(;;)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;  
}
#endif

#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_sig( int signo )
{
	printf("my_sig(%d)\n", signo );
	wait(0);
}

int main()
{
	int i;
	signal( SIGCHLD, my_sig );
	if( fork() == 0 )
	{
		for(i=0; i<3; i++ )
		{
			printf("\t\t\t\tchild\n");
			sleep(1);
		}
		exit(0);
	}
	for(;;)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;  
}
#endif
#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int i;
	if( fork() == 0 )
	{
		for(i=0; i<3; i++ )
		{
			printf("\t\t\t\tchild\n");
			sleep(1);
		}
		exit(0);
	}
	wait(0);
	for(;;)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;  
}
#endif
#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int i;
	if( fork() == 0 )
	{
		for(i=0; i<3; i++ )
		{
			printf("\t\t\t\tchild\n");
			sleep(1);
		}
		exit(0);
	}
	for(;;)
	{
		printf("parent\n");
		sleep(1);
	}
	return 0;  
}
#endif

#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char *argv[] = { "ls", (char*)0 };
	printf("prompt > ls\n");
	if( fork() == 0 )
		execve("/bin/ls", argv, 0);
	wait(0);
	printf("prompt > \n");
	return 0;  // exit(main());
}
#endif
#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	char *argv[] = { "ls", (char*)0 };
	printf("prompt > ls\n");
	if( fork() == 0 )
		execve("/bin/ls", argv, 0);
	sleep(1);
	printf("prompt > \n");
	return 0;  // exit(main());
}
#endif
#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	char *argv[] = { "ls", (char*)0 };
	printf("prompt > ls\n");
	execve("/bin/ls", argv, 0);
	printf("prompt > \n");
	return 0;
}
#endif
#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	char *argv[] = { "ls", (char*)0 };
	execve("/bin/ls", argv, 0);
	printf("after\n");
	return 0;
}
#endif

#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	pid = fork();
	if( pid == 0 )
		printf("child\n");
	else
		printf("parent\n");
	return 0;
}
#endif

#if 0
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	fork();
	printf("after\n");
	return 0;
}
#endif
