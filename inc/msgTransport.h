
#ifndef  __MSG_TRANSPORT_H__
#define  __MSG_TRANSPORT_H__
#include "global.h"
#include "cThread.h"
#include "zlibnet.h"
namespace baseservice
{
    class Message
    {
public:
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
            static int readHeader(const void *buf, int size, char magic[],unsigned int &type, unsigned int &DataLen);
            Message();
            virtual ~Message();
            void *getData();
            int getLen();
            int getType();
            int setData2Buffer(void *buf,int bufLen);
            int getDataFromBuffer(const void *buf,int bufLen);
            int setType(int type);
            int setMagic(const char magic[4]);
            std::string getMagic();
            void release();
            int setData(const void *data,int len);
        private:
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
