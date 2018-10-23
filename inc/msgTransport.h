
#ifndef  __MSG_TRANSPORT_H__
#define  __MSG_TRANSPORT_H__
#include "global.h"
#include "cThread.h"
#include "zlibnet.h"
namespace baseservice
{
    class Message
    {
    enum {
        SUCCESS=0,
        VAILD_TYPE=-999,
        VAILD_LEN,
        VAILD_DATA,
        VAILD_MAGIC,
        VAILD_ALLOC_FAIL,
        VAILD_DUP_TYPE,
        VAILD_OTHER
        };
        public:
            void *getData();
            int getLen();
            int getType();
            int setData2Buffer(void *buf,int bufLen);
            int setData(void *data,int len);
            int setType();
            int setMagic();
        private:
            void *ptr;
            int len;
            int type;
            char magic[4];

    };
    class MessageWorker
    {
        public:
        MessageWorker(int type);
        virtual ~MessageWorker();
        virtual int dealMsg(void * buf,int len);
        private:
        MessageWorker();
        int type;
    };
    class MessageSender
    {

    };
    class MessageMananger:public cThread
    {
        public:
        virtual int registWorker(MessageWorker *);
        virtual int run();
        
        typedef std::vector<MessageWorker*> WokerQueue;
        typedef std::vector<Message* > MessageQueue;
        private:

        WokerQueue mWQ_;
        MessageQueue mMQ;
        LOCKER mWQL,mMQL;
    };
};

#endif
