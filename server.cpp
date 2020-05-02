#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <string.h>

#define PORT 8080
#define LISTENQ 3

int main()
{
    int connfd;
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
        std::cout << "create socket failed" << std::endl;

    sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    int bind_ok = bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if(bind_ok < 0)
        std::cout << "bind socket with server address failed" << bind_ok << std::endl;

    int listen_ok = listen(listenfd, LISTENQ);
    if(listen_ok < 0)
        std::cout << "listen socket failed" << std::endl;

    std::string buffer = "hello, this is a simple server. \n";

    int write_ok = 0;

    int client_st = 0;
    socklen_t len = 0;
    sockaddr_in clinet_addr;
    void* ptr = &clinet_addr;
    char s[1024];

    while(true)
    {
        bzero(&clinet_addr, sizeof(clinet_addr));
        socklen_t len = sizeof(clinet_addr);
        client_st = accept(listenfd, (struct sockaddr*)&clinet_addr, &len);
        if(client_st != 0)
            std::cout << "accept failed" << std::endl;

        while(true)
        {
            memset(s, 0, sizeof(1024));

            int rc = recv(client_st, s, sizeof(s), 0);
            if(rc > 0)
            {
                std::cout << "receive success " << (std::string)(s) << std::endl;

            }
            else if(rc == 0)
            {
                std::cout << "receive close" << std::endl;
                break;
            }
            else
            {
                std::cout << "recieve failed";
                break;
            }

            std::string str = "this is server";
            int send_ok = send(client_st, str.c_str(), strlen(str.c_str()), 0);
            if(send_ok == -1)
                std::cout << "server send failed" << std::endl;
        }
        close(client_st);
    }

    close(connfd);

    return 0;
}
