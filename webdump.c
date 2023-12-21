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
	int sockfd;
  char buffer[1024];
  //ソケットを作る
	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd == -1){
		perror("socket: ");
	}
	else{
		printf("Created!\n");
	}
	//アドレスを作る
	if(memset(&serv_addr, 0, sizeof(struct sockaddr_in)) == NULL){
		perror("memset: ");
	}
  //ポート番号80を割り振る
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(80);
  //ソケットにアドレスを割り当てる
	if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) == -1){
		perror("bind: ");
	}
	else{
		printf("Socket binded!\n");
	}
  //コネクションの要求を待つ
  listen(sockfd,5);
  //要求を受け入れる
  new_sockfd=accept(sockfd,NULL,NULL);

  FILE*istream;
  //ソケットをファイルストリームへと変換する
  istream=fopen(new_sockfd,"r+");
  if(istream == NULL){
    perror("fdopen:");
  }
  //
  if(setvbuf(istream,NULL,_IONBF,0) != 0){
    perror("setvbuf:");
  }

  while(fgets(buff, 1024, istream) == 0){
    printf("%s", buff);
  }
  fclose(istream);
}
