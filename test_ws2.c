//
// Created by Administrator on 2022/6/13.
//
#include<stdio.h>
#include <stdlib.h>
#include <winsock2.h>

int main(){
  WSADATA wsadata;
  SOCKET hServSock;
  WSAStartup(MAKEWORD(2,2),&wsadata);
  hServSock = socket(PF_INET,SOCK_STREAM,0);
  closesocket(hServSock);
  WSACleanup();
}