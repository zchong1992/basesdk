

/******************************************
*   author: zc							  *	
*   date:  2018/2/26					  *
*	���ļ�Ϊ����ģ��ļ�࿪�������࣬    *
*   ���ٿ���ʱ��һЩ�������ظ��Թ�������  *
*******************************************/


#ifndef __ZLIBNET_H__
#define __ZLIBNET_H__
#include "global.h"
namespace baseservice
{
	struct zlibNetAddr
	{
		unsigned int ip;
		unsigned short port;
        
	};
	class tcpClient{
        public:
        tcpClient();
        ~tcpClient();
        int init();
        int release();
        int connect(zlibNetAddr);
        int connect(const char *ip,const char *port);
        int connect(const char *ip,unsigned short port);
        int send(const void * buf,int size,int flag);
        int recv(void * buf,int bufSize,int flag);
        int fd;
	};
	class tcpServer{
        public:
        tcpServer();
        ~tcpServer();
        int init();
        int bind(zlibNetAddr);
        int bind(const char *ip,const char *port);
        int bind(const char *ip,unsigned short port);
        int release();
        int listen(int maxNum);
        int accept(zlibNetAddr *);  
        int accept();  
        int fd;
    };
    class udpSocket
    {
    	udpSocket();
        ~udpSocket();
    	int init();
        int recv();
        int send();
        int fd;
    };
        
};




#endif



