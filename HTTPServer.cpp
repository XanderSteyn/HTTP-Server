#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

void Error(const char* msg) {
    cerr << msg << endl;
    exit(1);
}

void HandleClient(SOCKET ClientSocket) {
    char Buffer[2048];
    int BytesReceived;

    BytesReceived = recv(ClientSocket, Buffer, sizeof(Buffer), 0);
    if (BytesReceived < 0) {
        cerr << "Error receiving request." << endl;
        return;
    }

    Buffer[BytesReceived] = '\0';
    cout << "Request : \n" << Buffer << endl;

    string Response = "HTTP/1.1 200 OK\r\n";
    Response += "Content-Type : text/html; charset=UTF-8\r\n";
    Response += "Connection : close\r\n\r\n";
    Response += "<html><body><h1>This is a Simple HTTP Response</h1></body></html>";

    send(ClientSocket, Response.c_str(), Response.length(), 0);

    closesocket(ClientSocket);
}

int main() {
    WSADATA wsaData;
    SOCKET ServerSocket, ClientSocket;
    sockaddr_in ServerAddress, ClientAddress;
    int ClientAddressSize = sizeof(ClientAddress);

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        Error("WSAStartup Failed!");
    }

    ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ServerSocket == INVALID_SOCKET) {
        Error("Socket Creation Failed!");
    }

    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_addr.s_addr = INADDR_ANY;
    ServerAddress.sin_port = htons(8080);

    if (bind(ServerSocket, (struct sockaddr*)&ServerAddress, sizeof(ServerAddress)) == SOCKET_ERROR) {
        Error("Binding Failed!");
    }

    if (listen(ServerSocket, 5) == SOCKET_ERROR) {
        Error("Listener Failed!");
    }

    cout << "Server listening on port 8080..." << endl;

    while (true) {
        ClientSocket = accept(ServerSocket, (struct sockaddr*)&ClientAddress, &ClientAddressSize);
        if (ClientSocket == INVALID_SOCKET) {
            Error("Accept Failed!");
        }

        cout << "Client Connected" << endl;

        HandleClient(ClientSocket);
    }

    closesocket(ServerSocket);
    WSACleanup();

    return 0;
}