// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <time.h>
#define PORT	 8090 
#define MAXLINE 1024 

// Driver code 
int main() { 
	int sockfd; 
	struct sockaddr_in servaddr; 
	struct timespec t1, t2, ts;
	FILE *fp;
	fp = fopen("udp_lan.txt", "a+");
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	memset(&servaddr, 0, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_addr.s_addr = inet_addr("10.128.0.35");; 
	int n, len; 
	clock_gettime(CLOCK_REALTIME, &t1);
	sendto(sockfd, NULL, 0, MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
	n = recvfrom(sockfd, (char *)&ts , MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
	clock_gettime(CLOCK_REALTIME, &t2);
	printf("T1 : %ld.%ld\n", t1.tv_sec, t1.tv_nsec); 
	printf("TS : %ld.%ld\n", ts.tv_sec, ts.tv_nsec); 
	printf("T2 : %ld.%ld\n", t2.tv_sec, t2.tv_nsec); 
	printf("%ld\n%ld\n%04ld\n", (t2.tv_nsec+t1.tv_nsec)/2, ts.tv_nsec, (-(t2.tv_nsec+t1.tv_nsec)/2 + ts.tv_nsec)); 
	fprintf(fp, "%ld.%ld,%ld.%ld,%ld.%ld\n", t1.tv_sec, t1.tv_nsec, ts.tv_sec, ts.tv_nsec, t2.tv_sec, t2.tv_nsec);
	close(sockfd); 
	return 0; 
} 

