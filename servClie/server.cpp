//1.открыть сокет

/*
2,задать адресс и порт
3,слушаю
4,если пришло создать сокет для конекшена

5,читаю запрос
6,парсим первую строку чтоб получить команду
7,выполнить команду
8,вставляешь вывод в шаблон который содержит хедер и тело запроса
9,отправляешь ответ
10,закрываешь конекшин
*/
#include <iostream>
#include <winsock2.h>
#include <string>
#include <fstream>
#pragma comment(lib,"ws2_32")
int main(int argc, char* argv[]) {
    WSAData wsaData;
    WORD DllVersion = MAKEWORD(2,1);
    
    if(WSAStartup(DllVersion, &wsaData) !=0){
        std::cout<<"Errore WSA!\n";
        exit(1);
    }
    else
        std::cout<<"Server up\n";
    
    SOCKADDR_IN addr;
    int sizeOfAddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.7.2");
    addr.sin_port = htons(8000);
    addr.sin_family = AF_INET;

    SOCKET sListen =socket(AF_INET,SOCK_STREAM,0);
    bind(sListen, (SOCKADDR*)&addr,sizeof(addr));
    listen(sListen, SOMAXCONN);

    
    SOCKET newConnection;
    newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeOfAddr);
    if(newConnection == 0 )
        std::cout<<"New Connection Error!\n";
    else{
        
        //send(newConnection, str, sizeof(str),NULL);
        std::cout<<"New Connection \"Success\"\n";
        char msg[256]={"hello"};
        recv(newConnection, msg, sizeof(msg), 0);
    }
    system("pause");
    return 0;

}