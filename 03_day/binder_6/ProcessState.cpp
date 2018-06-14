#if 1
#include <stdio.h>
class ProcessState
{
	static ProcessState *gProcess;
	ProcessState()
	{
		printf("fd=open(\"/dev/binder\", O_RDWR)\n");
	}
	public:
	static ProcessState *self()
	{
		if( gProcess == 0 )
			gProcess = new ProcessState;
		return gProcess;
	}
	~ProcessState()
	{
		printf("close(fd)\n");
	}
};
ProcessState *ProcessState::gProcess = 0;

int main()
{
	ProcessState *p1 = ProcessState::self();
	ProcessState *p2 = ProcessState::self();
	//ProcessState process; 
	return 0;
}
#endif

#if 0
#include <stdio.h>
class ProcessState
{
	public:
		ProcessState()
		{
			printf("fd=open(\"/dev/binder\", O_RDWR)\n");
		}
		~ProcessState()
		{
			printf("close(fd)\n");
		}
};

int main()
{
	ProcessState p1;
	ProcessState p2;
	return 0;
}
#endif
