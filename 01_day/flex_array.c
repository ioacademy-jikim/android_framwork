#if 1
#include <stdio.h>
struct aaa
{
	int count;
	int b[];
};

int main()
{
	struct aaa *pa;
	pa = (struct aaa*)malloc( sizeof(struct aaa) + sizeof(int)*10 );
	pa->count = 10;
	pa->b[9] = 10;
	return 0;
}
#endif

#if 0
#include <stdio.h>
struct aaa
{
	int a;
	int b[];
};

int main()
{
	struct aaa aaa;
	printf("%lu\n", sizeof aaa );
	return 0;
}
#endif
