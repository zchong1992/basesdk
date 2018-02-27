#include "libbaseservice.h"

using namespace std;
using namespace baseservice;
void* createServer(void* a)
{
    tcpServer ts;
    int ret=ts.init();
    if(ret<0)
    {
        SYS_LOG(ZLOGINFO,"server init fail\n");
        return 0;
    }
    ret=ts.bind("0.0.0.0","8181");
    if(ret!=0)
    {
        SYS_LOG(ZLOGINFO,"server bind fail ret=%d\n",ret);
        return 0;
    }
    SYS_LOG(ZLOGINFO,"server bind success\n");
    ret=ts.listen(10);;
    if(ret!=0)
    {
        SYS_LOG(ZLOGINFO,"server listen fail ret=%d\n",ret);
        return 0;
    }
    zlibNetAddr  client;
    while(1)
    {
        ret=ts.accept(&client);
        if(ret<=0)
        {
            SYS_LOG(ZLOGINFO,"server listen fail ret=%d\n",ret);
            return 0;
        }
        SYS_LOG(ZLOGINFO,"new client connect in(%s:%d)\n",inet_ntoa(*(in_addr*)&client.ip),ntohs(client.port));
        usleep(1000);
    }
}
void* createClient(void* a)
{
    tcpClient tc;
    int ret=tc.init();
    if(ret<0)
    {
        SYS_LOG(ZLOGINFO,"client init fail ret=%d\n",ret);
        return 0;
    }
    ret=tc.connect("127.0.0.1","8181");
    if(ret<0)
    {
        SYS_LOG(ZLOGINFO,"client connect fail ret=%d\n",ret);
        return 0;
    }
    
}
int main(int argc ,char * argv[])
{
	//printf("test success\n");
	znlog *zl=znlog::getInstance();
    zl->set_level(ZLOGINFO,ZLOGINFO);
    zl->set_log_file("roc.log");
    createthread(createServer,0);
    usleep(1000*100);
    createthread(createClient,0);
    while(1)
    {
        printf(".");
        fflush(stdout);
        usleep(1000*100);
    }
    
    
	return 0;

}