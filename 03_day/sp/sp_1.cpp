#if 1
#include <stdio.h>
#include <utils/RefBase.h>
#include <utils/StrongPointer.h>

using namespace android;

class AAA;
class BBB;

class AAA : public virtual RefBase
{
	public:
		wp<BBB> pb;
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};
class BBB : public virtual RefBase
{
	public:
		wp<AAA> pa;
		BBB(){ printf("BBB::BBB()\n"); }
		~BBB() { printf("BBB::~BBB()\n"); }
		void foo() { printf("BBB::foo()\n"); }
};

int main()
{
	{
		sp<AAA> p1 = new AAA;
		sp<BBB> p2 = new BBB;
		p1->pb = p2;
		p2->pa = p1;
	}
	return 0;
}
#endif



#if 0
#include <stdio.h>
#include <utils/RefBase.h>
#include <utils/StrongPointer.h>

using namespace android;

class AAA;
class BBB;

class AAA : public virtual RefBase
{
	public:
		sp<BBB> pb;
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};
class BBB : public virtual RefBase
{
	public:
		sp<AAA> pa;
		BBB(){ printf("BBB::BBB()\n"); }
		~BBB() { printf("BBB::~BBB()\n"); }
		void foo() { printf("BBB::foo()\n"); }
};

int main()
{
	{
		sp<AAA> p1 = new AAA;
		sp<BBB> p2 = new BBB;
		p1->pb = p2;
		p2->pa = p1;
	}
	return 0;
}
#endif



