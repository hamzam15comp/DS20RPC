// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <time.h>
#define PORT	8090 
#define MAXLINE 1024 

// Driver code 
int main() { 
	int sockfd; 
	int len, n; 
	struct timespec ts;
	struct sockaddr_in servaddr, cliaddr; 
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ){ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	while(1){
		len = sizeof(cliaddr); //len is value/resuslt 
		n = recvfrom(sockfd, NULL, 0, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len); 
       		clock_gettime(CLOCK_REALTIME, &ts);	
		sendto(sockfd, (char *)&ts, sizeof(ts), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len); 
		printf("Tserver sent.\n"); 
	}
	return 0; 
} 

