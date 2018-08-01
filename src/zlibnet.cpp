

#include "zlibnet.h"
#include "log.h"
namespace baseservice {

tcpClient::tcpClient() { fd = 0; }
tcpClient::~tcpClient() { release(); }
int tcpClient::init() {

  fd = socket(AF_INET, SOCK_STREAM, 0);
  return fd;
}
int tcpClient::release() {

  if (fd != 0)
#ifdef ZWINDOWS
    ::closesocket(fd);
#else
    ::close(fd);
#endif
  fd = 0;
  return 0;
}
int tcpClient::connect(zlibNetAddr addr) {

#ifdef ZWINDOWS
  struct sockaddr_in serAddr;
  serAddr.sin_family = AF_INET;
  serAddr.sin_port = addr.port;
  serAddr.sin_addr.S_un.S_addr = addr.ip;
  return ::connect(fd, (sockaddr *)&serAddr, sizeof(serAddr));
#endif
#ifdef ZLINUX
  struct sockaddr_in serAddr;
  serAddr.sin_family = AF_INET;
  serAddr.sin_port = addr.port;
  serAddr.sin_addr.s_addr = addr.ip;
  return ::connect(fd, (sockaddr *)&serAddr, sizeof(serAddr));
#endif
}
int tcpClient::connect(const char *ip, const char *port) {
  zlibNetAddr addr;
  addr.ip = inet_addr(ip);
  addr.port = ntohs(atoi(port));
  return connect(addr);
}
int tcpClient::connect(const char *ip, unsigned short port) {
  zlibNetAddr addr;
  addr.ip = inet_addr(ip);
  addr.port = ntohs(port);
  return connect(addr);
}
int tcpClient::send(const void *buf, int size, int flag) {

  return ::send(fd, (char *)buf, size, flag);
}
int tcpClient::recv(void *buf, int bufSize, int flag) {

  return ::recv(fd, (char *)buf, bufSize, flag);
}
tcpServer::tcpServer() { fd = 0; }
tcpServer::~tcpServer() { release(); }
int tcpServer::init() {

  fd = socket(AF_INET, SOCK_STREAM, 0);
  int flag = 1, len = sizeof(int);
  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&flag, len) ==
      -1) {
    return -1;
  }
  return fd;
}
int tcpServer::bind(zlibNetAddr addr) {
#ifdef ZLINUX
  SOCKADDR_IN addrSrv;
  addrSrv.sin_addr.s_addr = addr.ip;
  addrSrv.sin_port = addr.port;
  addrSrv.sin_family = AF_INET;
  SYS_LOG(ZLOGINFO, "bind %s:%d\n", inet_ntoa(addrSrv.sin_addr),
          ntohs(addr.port));
  return ::bind(fd, (SOCKADDR *)&addrSrv, sizeof(SOCKADDR));
#endif
#ifdef ZWINDOWS
  SOCKADDR_IN addrSrv;
  addrSrv.sin_family = AF_INET;
  addrSrv.sin_port = addr.port;
  addrSrv.sin_addr.S_un.S_addr = addr.ip;
  return ::bind(fd, (SOCKADDR *)&addrSrv, sizeof(SOCKADDR));
#endif
  return 0;
}
int tcpServer::bind(const char *ip, const char *port) {
  zlibNetAddr addr;
  addr.ip = inet_addr(ip);
  addr.port = ntohs(atoi(port));
  return bind(addr);
}
int tcpServer::bind(const char *ip, unsigned short port) {
  zlibNetAddr addr;
  addr.ip = inet_addr(ip);
  addr.port = ntohs(port);
  return bind(addr);
}
int tcpServer::release() {
  if (fd != 0)
#ifdef ZWINDOWS
    ::closesocket(fd);
#else
    ::close(fd);
#endif
  fd = 0;
  return 0;
}
int tcpServer::listen(int maxNum) { return ::listen(fd, maxNum); }
int tcpServer::accept(zlibNetAddr *clientAddr) {
#ifdef ZLINUX
  SOCKADDR_IN addrSrv;
  int size=sizeof(SOCKADDR);
  int ret = ::accept(fd, (SOCKADDR *)&addrSrv, (socklen_t *)&size);
  clientAddr->ip = addrSrv.sin_addr.s_addr;
  clientAddr->port = addrSrv.sin_port;
  return ret;
#endif
#ifdef ZWINDOWS
  SOCKADDR_IN addrSrv;
  int size=sizeof(SOCKADDR);;
  int ret = ::accept(fd, (SOCKADDR *)&addrSrv, (socklen_t *)&size);
  clientAddr->ip = addrSrv.sin_addr.S_un.S_addr;
  clientAddr->port = addrSrv.sin_port;
  return ret;
#endif
}
int tcpServer::accept() {
  zlibNetAddr clientAddr;
  return accept(&clientAddr);
}
}; // namespace baseservice
