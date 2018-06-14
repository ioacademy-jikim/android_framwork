#if 1
#include <stdio.h>
#include <utils/RefBase.h>
#include <utils/StrongPointer.h>

using namespace android;

class AAA : public virtual RefBase
{
	int data;
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo()   // void foo( AAA *this )
		{ 
			data = 10;  // this->data = 10; => (*0).data = 10;
			printf("AAA::foo()\n"); 
		}
};

int main()
{
	//((AAA*)0)->foo();  // AAA::foo(0);
	{
		wp<AAA> p1 = new AAA;
		{
			sp<AAA> p2 = p1.promote();
			p2->foo();
		}
		printf("step 1.\n");
		if( p1.promote() != 0 )
			p1.promote()->foo();
		else
			printf("객체는 이미 소멸됨\n");
	}
	printf("step 2.\n");
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <utils/RefBase.h>
#include <utils/StrongPointer.h>

using namespace android;

class AAA : public virtual RefBase
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};

int main()
{
	{
		wp<AAA> p1 = new AAA;
		sp<AAA> p2 = p1.promote();
		p2->foo();
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <utils/RefBase.h>
#include <utils/StrongPointer.h>

using namespace android;

class AAA : public virtual RefBase
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};

int main()
{
	{
		sp<AAA> p1 = new AAA;
		wp<AAA> p2 = p1;
		p1->foo();
	}
	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <utils/RefBase.h>
#include <utils/StrongPointer.h>

using namespace android;

class AAA : public virtual RefBase
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};

int main()
{
	{
		wp<AAA> pa = new AAA;
		pa.promote()->foo();
	}
	return 0;
}
#endif



