#if 0
#include <stdio.h>
#include <utils/Thread.h>
#include <utils/StrongPointer.h>

using namespace android;
//--------------------------------------------------------
class AAA  : public RefBase
{
	int ratio=0;
	public:
		AAA()
		{
			printf("AAA::AAA()\n");
		}
		void onFirstRef()
		{
			ratio = 100;
			printf("AAA::onFirstRef()\n");
		}

		bool foo(void)
		{
			printf("AAA::foo()\n");
			return false;
		}
};
int main()
{
	sp<AAA> pa = new AAA;
	//AAA *pa = new AAA;
	pa->foo();
	//delete pa;
	return 0;
}
#endif

#if 1
#include <stdio.h>
#include <utils/Thread.h>
#include <utils/StrongPointer.h>

using namespace android;
//--------------------------------------------------------
class MyThread : public Thread
{
	int volume;
public:
	MyThread()
	{
		printf("MyThread::MyThread()\n");
	}
	void onFirstRef()
	{
		printf("MyThread::onFirstRef()\n");
	}
	status_t readyToRun()
	{
		printf("MyThread::readyToRun()\n");
		return NO_ERROR;
	}

	bool threadLoop(void)
	{
		volume=100;
		printf("MyThread::threadLoop(), volume=%d\n", volume);
		sleep(1);
		return true;
	}
};
int main()
{
	sp<Thread> thread = new MyThread;
	thread->run("MyThread");
	thread->join();
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>

class Thread
{
	pthread_t thread;
public:
	virtual void foo(void) = 0;
	static void * _foo(void *data )
	{
		Thread *self = (Thread*)data;
		self->foo();
		return 0;
	}
	void run()
	{
		pthread_create( &thread, 0, _foo, this );
	}
	void join()
	{
		pthread_join( thread, 0 );
	}
};
//--------------------------------------------------------
class MyThread : public Thread
{
	int volume;
public:
	void foo(void)
	{
		volume=100;
		printf("foo(), volume=%d\n", volume);
	}
};
int main()
{
	Thread *thread = new MyThread;
	thread->run();
	thread->join();
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>

class Thread
{
	pthread_t thread;
	int volume;
public:
	void foo(void)
	{
		volume=100;
		printf("foo(), volume=%d\n", volume);
	}
	static void * _foo(void *data )
	{
		Thread *self = (Thread*)data;
		self->foo();
		return 0;
	}
	void run()
	{
		pthread_create( &thread, 0, _foo, this );
	}
	void join()
	{
		pthread_join( thread, 0 );
	}
};
//--------------------------------------------------------
int main()
{
	Thread *thread = new Thread;
	thread->run();
	thread->join();
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>

class Thread
{
	pthread_t thread;
	int volume;
public:
	static void * foo(void *data )
	{
		printf("foo()\n");
		volume=100;
		return 0;
	}
	void run()
	{
		pthread_create( &thread, 0, foo, 0 );
	}
	void join()
	{
		pthread_join( thread, 0 );
	}
};
//--------------------------------------------------------
int main()
{
	Thread *thread = new Thread;
	thread->run();
	thread->join();
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <pthread.h>
class AAA
{
	int data;
	public:

	    void set_data( int _data )
		{
			data = _data;
		}

		static void foo(void)   // AAA::foo()
		{
			set_data(10);  // set_data(this, 10);
			printf("AAA::foo()\n");
		}
};

//--------------------------------------------------------
int main()
{
	void (*p)()  = &AAA::foo;
	(*p)();  // (*p)()
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>
class AAA
{
	public:

		void foo(void)   // AAA::foo(AAA *this)
		{
			printf("AAA::foo()\n");
		}
};

//--------------------------------------------------------
int main()
{
	//AAA aaa;
	//aaa.foo();  // AAA::foo(&aaa);
	AAA aaa;
	void (AAA::*p)()  = &AAA::foo;
	(aaa.*p)();  // (*p)(&aaa)
	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <pthread.h>
void foo(void) 
{
	printf("foo()\n");
}

//--------------------------------------------------------
int main()
{
	void (*p)(void)  = foo; 
	p();
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>
void * foo(void *data )
{
	printf("foo()\n");
	return 0;
}

class Thread
{
	pthread_t thread;
public:
	void run()
	{
		pthread_create( &thread, 0, foo, 0 );
	}
	void join()
	{
		pthread_join( thread, 0 );
	}
};
//--------------------------------------------------------
int main()
{
	Thread *thread = new Thread;
	thread->run();
	thread->join();
	return 0;
}
#endif



#if 0
#include <stdio.h>
#include <pthread.h>
void * foo(void *data )
{
	printf("foo()\n");
	return 0;
}
int main()
{
	pthread_t thread;
	pthread_create( &thread, 0, foo, 0 );
	pthread_join( thread, 0 );
	return 0;
}
#endif
