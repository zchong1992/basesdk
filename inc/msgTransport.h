
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
        VAILD_BUFFER,
        VAILD_ALLOC_FAIL,
        VAILD_DUP_TYPE,
        VAILD_OTHER
        };
        public:
            static int writeHeader(void *buf, int size, char magic[],unsigned int type, unsigned int DataLen);
            static int readHeader(void *buf, int size, char magic[],unsigned int &type, unsigned int &DataLen);
            Message();
            virtual ~Message();
            void *getData();
            int getLen();
            int getType();
            int setData2Buffer(void *buf,int bufLen);
            int getDataFromBuffer(void *buf,int bufLen);
            int setType(int type);
            int setMagic(char magic[4]);
            void release();
        private:
            int setData(void *data,int len);
            void *mPtr;
            int mLen;
            int mType;
            char mMagic[4];
            LOCKER mLocker;
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
