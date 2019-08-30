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

int main(int argc, char*argv[] ){
	///socket
	int sock_client, new_sockfd;
	struct sockaddr_in sin_addr,pin_addr;
	int len, pin_addr_size, i;
	
	if( (sock_client = socket(AF_INET, SOCK_STREAM,0)) <0 ){
		printf("can't create socket\n");
		exit(1);
	}
	
	memset( &sin_addr, 0, sizeof(sin_addr) );
	sin_addr.sin_family = AF_INET;
	sin_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	sin_addr.sin_port = htons(myport);
	
	//connect
	if( (new_sockfd = connect( sock_client, 
		(struct sockaddr*) &sin_addr, sizeof(sin_addr)  ) ) < 0 ){
		
		perror("connect error\n");
		return 1;
	}
	else printf("connect success!\n");
	
	//send
	while(1){
		//memset(buf,'\0',sizeof(buf));
		
		gets(buf);
		//scanf("%s",buf);
		
		//connect
		/*if( (new_sockfd = connect( sock_client, 
			(struct sockaddr*) &sin_addr, sizeof(sin_addr)  ) ) < 0 ){
			
			perror("connect error\n");
			return 1;
		}
		else printf("connect success!\n");*/
	
		//recv
		/*if(recv(sock_client, buf, 200, 0) == -1){      
        	printf("can’t receive packet\n");
        	exit(1);
      	}
      	else
      		printf("received from sever:%s\n", buf);*/
		
		//send
		if( send(sock_client, buf, 200, 0) ==-1 ){
			printf("can't send packet\n");
			exit(1);
		}
		printf("send to server: %s\n",buf );
		//close(new_sockfd);  //加上这句会造成循环打印send to server
	}
	
	return 0;
}

