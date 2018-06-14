#if 1
#include <stdio.h>

class RefBase
{
	int mRefs;
	public:
		RefBase():mRefs(0) { printf("RefBase::RefBase()\n"); }
		virtual ~RefBase() { printf("RefBase::~RefBase()\n"); }
		void incStrong() { 
			printf("RefBase::incStrong() : mRefs=%d\n", ++mRefs); 
		}
		void decStrong() 
		{ 
			--mRefs;
			printf("RefBase::decStrong() : mRefs=%d\n", mRefs); 
			if( mRefs == 0 )
				delete this;
		}
};
class AAA : public virtual RefBase
{
	public:
		AAA(){ printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};

template < typename T >
class sp
{
	T *mPtr;
	public:
		sp( T *ptr):mPtr(ptr) { 
			printf("sp::sp(T)\n"); 
			mPtr->incStrong();
		}
		sp( const sp<T> &r ) : mPtr(r.mPtr) { 
			printf("sp::sp(sp<T>)\n"); 
			mPtr->incStrong();
		}

		~sp() { 
			printf("sp::~sp()\n"); 
			mPtr->decStrong();
		}

		T * operator->()
		{
			return mPtr;
		}
		T operator*()
		{
			return *mPtr;
		}
};

int main()
{
	{
		sp<AAA> p1 = new AAA;
		sp<AAA> p2 = p1;
		p1->foo();  
		p2->foo();  
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	int mRefs;
	public:
		AAA():mRefs(0) { printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
		void incStrong() { 
			printf("AAA::incStrong() : mRefs=%d\n", ++mRefs); 
		}
		void decStrong() 
		{ 
			--mRefs;
			printf("AAA::decStrong() : mRefs=%d\n", mRefs); 
			if( mRefs == 0 )
				delete this;
		}
};

template < typename T >
class sp
{
	T *mPtr;
	public:
		sp( T *ptr):mPtr(ptr) { 
			printf("sp::sp(T)\n"); 
			mPtr->incStrong();
		}
		sp( const sp<T> &r ) : mPtr(r.mPtr) { 
			printf("sp::sp(sp<T>)\n"); 
			mPtr->incStrong();
		}

		~sp() { 
			printf("sp::~sp()\n"); 
			mPtr->decStrong();
		}

		T * operator->()
		{
			return mPtr;
		}
		T operator*()
		{
			return *mPtr;
		}
};

int main()
{
	{
		sp<AAA> p1 = new AAA;
		sp<AAA> p2 = p1;
		p1->foo();  
		p2->foo();  
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA() { printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};

template < typename T >
class sp
{
	T *mPtr;
	static int mRefs;
	public:
		sp( T *ptr):mPtr(ptr) { 
			mRefs=1;
			printf("sp::sp(T), mRefs=%d\n", mRefs); 
		}
		sp( const sp<T> &r ) { 
			mRefs++;
			printf("sp::sp(sp<T>), mRefs=%d\n", mRefs); 
		}

		~sp() { 
			printf("sp::~sp()\n"); 
			if( --mRefs == 0 )
				delete mPtr;
		}

		T * operator->()
		{
			return mPtr;
		}
		T operator*()
		{
			return *mPtr;
		}
};

template < typename T >
int sp<T>::mRefs = 0;

int main()
{
	{
		sp<AAA> p1 = new AAA;
		sp<AAA> p2 = p1;
		p1->foo();  
		p2->foo();  
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA() { printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};

template < typename T >
class sp
{
	T *mPtr;
	public:
		sp( T *ptr):mPtr(ptr) { printf("sp::sp()\n"); }
		~sp() { 
			printf("sp::~sp()\n"); 
			delete mPtr;
		}

		T * operator->()
		{
			return mPtr;
		}
		T operator*()
		{
			return *mPtr;
		}
};

int main()
{
	{
		sp<AAA> p1 = new AAA;
		sp<AAA> p2 = p1;
		p1->foo();  
		p2->foo();  
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA() { printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};
class BBB
{
	public:
		BBB() { printf("BBB::BBB()\n"); }
		~BBB() { printf("BBB::~BBB()\n"); }
		void foo() { printf("BBB::foo()\n"); }
};

template < typename T >
class sp
{
	T *mPtr;
	public:
		sp( T *ptr):mPtr(ptr) { printf("sp::sp()\n"); }
		~sp() { 
			printf("sp::~sp()\n"); 
			delete mPtr;
		}

		T * operator->()
		{
			return mPtr;
		}
		T operator*()
		{
			return *mPtr;
		}
};

int main()
{
	{
		sp<AAA> pa = new AAA;
		pa->foo();  

		sp<BBB> pb = new BBB;
		pb->foo();  
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA() { printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};

class sp
{
	AAA *mPtr;
	public:
		sp( AAA *ptr):mPtr(ptr) { printf("sp::sp()\n"); }
		~sp() { 
			printf("sp::~sp()\n"); 
			delete mPtr;
		}

		AAA * operator->()
		{
			return mPtr;
		}
		AAA operator*()
		{
			return *mPtr;
		}
};

int main()
{
	{
		sp pa = new AAA;
		pa->foo();   // pa.operator->()->foo();

		(*pa).foo();
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA() { printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
		void foo() { printf("AAA::foo()\n"); }
};

class sp
{
	AAA *mPtr;
	public:
		sp( AAA *ptr):mPtr(ptr) { printf("sp::sp()\n"); }
		~sp() { 
			printf("sp::~sp()\n"); 
			delete mPtr;
		}
};

int main()
{
	{
		//AAA* pa = new AAA;
		//pa->foo();
		sp pa = new AAA;
		pa->foo();   // pa.operator->()->foo();
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA() { printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
};

int main()
{
	AAA *pa = new AAA;
	//...
	return 0;
}
#endif

#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA() { printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
};

int main()
{
	AAA *pa = new AAA;
	delete pa;
	//...
	return 0;
}
#endif

#if 0
#include <stdio.h>

class AAA
{
	public:
		AAA() { printf("AAA::AAA()\n"); }
		~AAA() { printf("AAA::~AAA()\n"); }
};

int main()
{
	AAA aaa;
	return 0;
}
#endif
