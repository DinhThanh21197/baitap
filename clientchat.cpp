#include<iostream>
#include<WS2tcpip.h>   
#include<string>
#include<sstream>
#pragma comment(lib,"WS2tcpip.h") // chỉ thị trình biên dịch
using namespace std;
void main() {
	// initialze winsock  -khởi tạo winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);
	int wsOk = WSAStartup(ver, &wsData);
	if (wsOk != 0) {
		cerr << "khong the khoi tao winskoc,bye" << endl;
		return;
	}
	// create a socket  -  socket
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << " khong the tao socket" << endl;
		return;
	}
	// bind the socket to an ip address and port - liên kết
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htond(54000);
	hint.sin_addr.S_un.S_addr = ADDR_ANY; // could also use inet_pton - su dung de chuyen doi ipv6
	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// tell winsock the socket is for listening
	listen(listening, SOMAXCONN);
	fd_set master;
	FD_ZERO(&master);
	FD_SET(listening,&master);
	while (true) {
		fd_set copy = master;
		int socketcount = select(0, &copy, nullptr, nullptr, nullptr);
		for (int i = 0; i < socketcount; i++)
		{
			SOCKET sock = copy.fd_array[i];
			if (sock==listening)
			{
				// accet a new connected
				SOCKET client = accept(listening, nullptr, nullptr);
				// add the new connection to the list of connected clients
				FD_SET(client, &master);
                // send a welcome massage to the connected client
				string welcomeMsg = "welcome to the chat sever";
				send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
                // Todo: broadcast we have a new connection


			}
			else {
				char buf[4096];
				ZeroMemory(buf, 4096);
				// reveive message
				int bytesIn = recv(sock, buf, 4096, 0);
				//accet a new connected
				//accept a new message
				if (bytesIn <= 0) {
					closesocket(sock);
					FD_CLR(sock, &master);

				}
				else {
					for (int i = 0; i < master.fd_count ;i++)
					{
						SOCKET outsock = master.fd_array[i];
						if (outsock!=listening &&outsock!=sock)
						{
							ostringstream ss;
							ss<<"SOCKER#: "<< buf<<"\r\n";
							string strOut = ss.str();
							send(outsock, buf, bytesIn, 0);
						}
					}
				}
                // send message to other cliens, and definiatey not the listening socket
			}
		}
	}


	// shutdown winsock
	WSACleanup();
}
