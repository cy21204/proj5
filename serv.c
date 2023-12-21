	111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111	qAZXZ#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

struct sockaddr_in serv_addr;

int main(){
	char buff[6];
	int sockfd, new_sockfd;
	//ソケットを作る
	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	//アドレスを作る
	memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(50000);
	//ソケットにアドレスを割り当てる
	if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) == -1){
		perror("bind: ");
	}
	else{
		printf("Socket binded!\n");
	}
	
	//コネクション要求を待たせる
	if(listen(sockfd, 5) == -1){
		perror("listen: ");
	}
	
	new_sockfd = accept(sockfd, NULL, NULL);
	if(new_sockfd == -1){
		perror("accept: ");
	}
	if((read(new_sockfd, buff, sizeof(buff))) == -1){
		perror("read;");
	}
	printf("%s\n", buff);
	.........633
	sleep(1);
	if(close(new_sockfd) == -1){
		perror("close: ");
	}
	if(close(sockfd) =																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																											= -1){
		perror("close: ");
	}
}
