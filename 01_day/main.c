#include <stdio.h>
#include <libgen.h>
#include <string.h>
// # /init
int main(int argc, char** argv) {
	printf("%s\n", basename(argv[0]));
    if (!strcmp(basename(argv[0]), "ueventd")) {
        //return ueventd_main(argc, argv);
		printf("ueventd\n");
    }
	return 0;
}

