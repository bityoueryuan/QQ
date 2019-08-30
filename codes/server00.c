#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define myport 5000
char buf[200];

//myport 端口号

int main(int argc, char *argv[])
{
	//socket
	int sockfd, new_sockfd;
	struct sockaddr_in sin_addr,pin_addr;
	int len, pin_addr_size, i;
	if( (sockfd = socket(AF_INET, SOCK_STREAM,0)) <0 ){
		printf("can't create socket\n");
		exit(1);
	}
	
	//bind
	memset( &sin_addr, 0, sizeof(sin_addr) );
	sin_addr.sin_family = AF_INET;
	sin_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	sin_addr.sin_port = htons(myport);
	if( bind(sockfd, (struct sockaddr*)&sin_addr, sizeof(sin_addr)) <0 ){
		printf("can't bind socket\n");
		exit(1);
	}
	
	//listen & accept
	if(listen(sockfd,5)< 0 ){
		printf("lsiten error\n");
		exit(1);
	}
	
	//accept
	if( (new_sockfd = accept(sockfd, 
		(struct sockaddr*) &pin_addr, &pin_addr_size)) < 0 ){
		
		printf("accept error\n");
		exit(1);
	}
	
	while(1){
		/*if( (new_sockfd = accept(sockfd, 
			(struct sockaddr*) &pin_addr, &pin_addr_size)) < 0 ){
			
			printf("accept error\n");
			exit(1);
		}*/
	
		//recv
		if( recv(new_sockfd, buf,200,0) ==-1){
			printf("can't receive packet\n");
			exit(1);
		}
		printf("received from client: %s\n",buf );
		//close(new_sockfd);
	}
	return 0;
}

//stray/342等等这些大多是中英文符号



