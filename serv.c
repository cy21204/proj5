#include <arpa/inet.h>
#include <string.h>
#include <sys.types.h>
#include <sys/socket.h>

struct sockaddr in serv_addr;

int main(){

	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	
	memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htnol(INADDR_ANY);
	serv_addr.sing_port(50000);
	
	bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in));
	
	listen(sockfd, 5);
	
	new_sockfd=accept(sockfd, NULL, NULL);
	
	read(new_sockfd, buff, 128);
	
	sleep(1);
	close(new_sockfd);
	close(sockfd);
}
