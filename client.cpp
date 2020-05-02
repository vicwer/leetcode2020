#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

#include<arpa/inet.h>

#include <unistd.h>
#include <string.h>

#define PORT 8080

int main()
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in client_addr;
    bzero(&client_addr, sizeof(client_addr));

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int connfd = connect(listenfd, (struct sockaddr*)&client_addr, sizeof(client_addr));
    if(connfd == -1)
        std::cout << "connect failed" << std::endl;

    std::string str = "this is client";

    int send_ok = send(listenfd, str.c_str(), strlen(str.c_str()), 0);
    if(send_ok == -1)
        std::cout << "client send failed" << std::endl;

    char s[1024];
    memset(s, 0, sizeof(1024));
    int rc = recv(listenfd, s, sizeof(s), 0);
    if(rc > 0)
        std::cout << "receive success " << (std::string)(s) << std::endl;
    else if(rc == 0)
        std::cout << "receive close" << std::endl;
    else
        std::cout << "recieve failed";

    close(listenfd);
    return 0;
}