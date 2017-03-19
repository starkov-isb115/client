#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include <WinSock2.h>
#include <iostream>
#include <stdlib.h>
#include <clocale>

#define DEFAULT_BUFLEN 512

SOCKET mySock;

void gAs()
{
	char get[DEFAULT_BUFLEN];
	while(true)
	{
		recv(mySock, get, sizeof(get), NULL);
		printf(get); printf("\n");
	}
}


int main()
{
	setlocale(LOCALE_ALL,"russian");
	WSAData wsaData;
	WORD sockver = MAKEWORD(2,2);
	if (WSAStartup(sockver, &wsaData) != 0 )
	{	
		exit(1);
	}

	SOCKADDR_IN address;
	int adresize = sizeof(address);
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(1997);
	address.sin_family = AF_INET;

	mySock = socket(AF_INET, SOCK_STREAM, NULL);
	if ( connect(mySock, (SOCKADDR*)&address, adresize) != 0)
	{
			return 1;
	} else 
		{
			printf("Подключен к серверу");
	
		}
	CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)gAs,NULL,NULL,NULL);

while(1)
	{
		char msg[DEFAULT_BUFLEN];
		std::cin.getline(msg, sizeof(msg));
		send(mySock, msg, sizeof(msg), NULL);
	}
	system("pause");

	return 0;
}