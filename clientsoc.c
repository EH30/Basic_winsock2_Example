#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

int main(int argc , char *argv[])
{
    if (argc < 1){
        printf("This Takes 1 Arrgument 0 given Example: ./clientsoc.exe [You're IP] [You're Port]");
        return 1;
    }

    char *ip = argv[1];
    char *port = argv[2];

    WSADATA wsa;
    SOCKET soc;
    SOCKADDR_IN addr;

    WSAStartup(MAKEWORD(2,0), &wsa);

    soc = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(port));

    connect(soc, (SOCKADDR *)&addr, sizeof(addr));

    
    char buffer[1025] = {'a', 'b', 'c'};
    char e[1025];
    send(soc, buffer, sizeof(buffer), 0);

    recv(soc, e, sizeof(e), 0);
    
    printf("%s", e);
    
    memset(e, 0, sizeof(e));

    closesocket(soc);
    WSACleanup();
    
    return 0;
}