#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32")
int main(int argc, char* argv[]) {
    //WSAStartup
    WSAData wsaData;
    WORD DllVersion = MAKEWORD(2,1);
    if(WSAStartup(DllVersion, &wsaData) !=0){
        std::cout<<"Errore WSA!\n";
        exit(1);
    }
    
    SOCKADDR_IN addr;
    int sizeOfAddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.7.2");
    addr.sin_port = htons(8000);
    addr.sin_family = AF_INET;

    SOCKET connection = socket(AF_INET,SOCK_STREAM,0);
    if(connect(connection,(SOCKADDR*)&addr, sizeof(addr)) != 0){
        std::cout<<"Connection field to server.\n";
        return 1;
    }
    std::cout<<"Connected succes.\n";
    char msg[256];
    recv(connection, msg, sizeof(msg),0);
    std::cout<<"[Message] - "<<msg<<"\n";
    
    system("pause");
    return 0;
}