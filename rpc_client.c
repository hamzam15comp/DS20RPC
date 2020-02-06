/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include<time.h>
#include "rpc.h"

struct Tserv result;

void
rpc_prog_1(char *host)
{
	CLIENT *clnt;
	struct Tserv  *result_1;
	char *rpc_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, RPC_PROG, RPC_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = rpc_1((void*)&rpc_1_arg, clnt);
	if (result_1 == (struct Tserv *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result = *result_1;
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	struct timespec start, stop;
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	FILE *fp;
	fp = fopen("rpc_localhost.txt", "a+");
	host = argv[1];
	clock_gettime(CLOCK_REALTIME, &start);
	rpc_prog_1 (host);
	clock_gettime(CLOCK_REALTIME, &stop);
//	printf("addrpc() took %ld . %ld milliseconds to execute \n", result.tv_sec, result.tv_nsec);
	fprintf(fp, "%ld.%ld,%ld.%ld,%ld.%ld\n", start.tv_sec, start.tv_nsec, result.sec, result.nsec, stop.tv_sec, stop.tv_nsec);
	fclose(fp);
	exit (0);
}
