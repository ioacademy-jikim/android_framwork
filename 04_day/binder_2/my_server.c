/* Copyright 2008 The Android Open Source Project
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "binder.h"

typedef struct
{
	void (*on)(void);
	void (*off)(void);
} LED_INFO;

int svcmgr_publish(struct binder_state *bs, uint32_t target, const char *name, void *ptr)
{
    int status;
    unsigned iodata[512/4];
    struct binder_io msg, reply;

    bio_init(&msg, iodata, sizeof(iodata), 4);
    bio_put_uint32(&msg, 0);  // strict mode header
    bio_put_string16_x(&msg, SVC_MGR_NAME);
    bio_put_string16_x(&msg, name);
    bio_put_obj(&msg, ptr);

    if (binder_call(bs, &msg, &reply, target, SVC_MGR_ADD_SERVICE))
        return -1;

    status = bio_get_uint32(&reply);

    binder_done(bs, &msg, &reply);

    return status;
}

int my_handler(struct binder_state *bs,
                              struct binder_transaction_data *txn,
                              struct binder_io *msg,
                              struct binder_io *reply)
{
	printf("my_handler %p %p %p %p\n", bs, txn, msg, reply);
	LED_INFO *Led = (LED_INFO*)txn->target.ptr;
	switch(txn->code) {
		case 1:
			{
				Led->on();
				return 0;
			}
		case 2:
			{
				Led->off();
				return 0;
			}

		default:
			printf("unknown code %d\n", txn->code);
			return -1;
	}

	bio_put_uint32(reply, 0);
	return 0;
}

void ledOn(void)
{
	printf("Server : ledOn\n");
}

void ledOff(void)
{
	printf("Server : ledOff\n");
}

int main(int argc, char **argv)
{
	struct binder_state *bs;
	uint32_t svcmgr = BINDER_SERVICE_MANAGER;
	LED_INFO *Led;

	bs = binder_open("/dev/binder", 128*1024);
	if (!bs) {
		fprintf(stderr, "failed to open binder driver\n");
		return -1;
	}
	Led = (LED_INFO*)malloc( sizeof(LED_INFO) );
	Led->on = ledOn;
	Led->off = ledOff;

	printf("Server : &token = %p\n", Led );
	svcmgr_publish(bs, svcmgr, argv[argc-1], Led);
	binder_loop(bs, my_handler);
	return 0;
}



