#if 1
#include <stdio.h>
#include <utils/Thread.h>
#include <utils/StrongPointer.h>
#include <binder/IPCThreadState.h>

using namespace android;
//--------------------------------------------------------

class MyThread : public Thread
{
	public:
		bool threadLoop()
		{
			IPCThreadState *ipc1 = IPCThreadState::self();
			IPCThreadState *ipc2 = IPCThreadState::self();
			printf("ipc1=%p\n", ipc1 );
			printf("ipc2=%p\n", ipc2 );
			return false;
		}
};
int main()
{
	sp<Thread> thread1 = new MyThread;
	sp<Thread> thread2 = new MyThread;
	thread1->run("MyThread1");
	thread2->run("MyThread2");
	thread1->join();
	thread2->join();

	return 0;
}
#endif







