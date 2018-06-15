#if 1
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_key_t key;

void foo(void)
{
	int *count = (int *)pthread_getspecific(key);
	if( count == 0 )
	{
		count = new int(0);
		printf("count=%p\n", count);
		pthread_setspecific(key, count);
	}
	printf("foo() : %d\n", ++*count ); 
}
//-------------------------------------------------------
void *handler_1(void *data)
{
	foo();
	foo();
	foo();
	return 0;
}

void *handler_2(void *data)
{
	foo();
	foo();
	return 0;
}
void my_destructor(void* p)
{
	printf("my_destructor(%p)\n", p );
	delete (int*)p;
}

int main()
{
	pthread_t thread[2];
	pthread_key_create(&key, my_destructor);
	printf("key=%d\n", key );
	pthread_create( &thread[0], 0, handler_1, 0 );
	pthread_create( &thread[1], 0, handler_2, 0 );
	pthread_join( thread[0], 0 );
	pthread_join( thread[1], 0 );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void foo(int *count)
{
	++*count;
	printf("foo() : %d\n", *count ); 
}

void *handler_1(void *data)
{
	int count=0;
	foo(&count);
	foo(&count);
	foo(&count);
	return 0;
}

void *handler_2(void *data)
{
	int count=0;
	foo(&count);
	foo(&count);
	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create( &thread[0], 0, handler_1, 0 );
	pthread_create( &thread[1], 0, handler_2, 0 );
	pthread_join( thread[0], 0 );
	pthread_join( thread[1], 0 );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
void *foo(void *data)
{
	char ip[] = "192.168.56.100";
	char *p;
	char *saveptr;

	p = strtok_r( ip , "." , &saveptr);
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok_r( saveptr , "." , &saveptr);
		sleep(1);
	}
	return 0;
}
void *bar(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;
	char *saveptr;

	p = strtok_r( hp , "-" , &saveptr);
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok_r( saveptr , "-" , &saveptr);
		sleep(1);
	}
	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create( &thread[0], 0, foo, 0 );
	pthread_create( &thread[1], 0, bar, 0 );
	pthread_join( thread[0], 0 );
	pthread_join( thread[1], 0 );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
void *foo(void *data)
{
	char ip[] = "192.168.56.100";
	char *p;

	p = strtok( ip , "." );
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0 , "." );
		sleep(1);
	}
	return 0;
}
void *bar(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;

	p = strtok( hp , "-" );
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0 , "-" );
		sleep(1);
	}
	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create( &thread[0], 0, foo, 0 );
	pthread_create( &thread[1], 0, bar, 0 );
	pthread_join( thread[0], 0 );
	pthread_join( thread[1], 0 );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>
int main()
{
	char ip[] = "192.168.56.100";
	char *p;

	p = strtok( ip , "." );
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok( 0 , "." );
	}
	return 0;
}
#endif
