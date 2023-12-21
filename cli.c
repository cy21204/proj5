#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

struct sockaddr_in serv_addr;


int main(){
	int val;
	char buff[6] = "hello";
	int sockfd;
	

	
	sockfd=socket(AF_INET, SOCK_STREAM,0);
	if(sockfd == -1){
		perror("socket: ");
	}
	else{
		printf("Created!\n");
	}

	memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(50000);
	
	connect(sockfd, (struct sockaddr *)&serv_addr,sizeof(struct sockaddr_in));
	
	write(sockfd,(void *)buff,5);
	
	close(sockfd);
}
