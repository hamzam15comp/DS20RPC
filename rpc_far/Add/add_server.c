/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include<time.h>
#include "add.h"



int *
add_1_svc(intpair *argp, struct svc_req *rqstp)
{
	struct timespec t_server;
	clock_gettime(CLOCK_REALTIME, &t_server);
//	write(0, "Server boi active\n", 19);
	return &t_server;
}
