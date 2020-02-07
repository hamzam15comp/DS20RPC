struct Tserv{
	unsigned long int sec;
	unsigned long int nsec; 
};
program RPC_PROG {
	version RPC_VERS {
		struct Tserv RPC(void) = 1;
	} = 1; 
} = 0x23451111;
