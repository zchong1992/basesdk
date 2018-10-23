#include "msgTransport.h"

using namespace std;
namespace baseservice
{
    // enum {
    //     SUCCESS=0,
    //     VAILD_TYPE=-999,
    //     VAILD_LEN,
    //     VAILD_DATA,
    //     VAILD_MAGIC,
    //     VAILD_ALLOC_FAIL,
    //     VAILD_DUP_TYPE,
    //     VAILD_OTHER
    //     };
    //     public:
    void *Message::getData()
    {
        return ptr;
    }
    int Message::getLen()
    {
        return len;
    }
    int Message::getType()
    {
        return type;
    }
    int Message::setData2Buffer(void *buf, int bufLen)
    {
        return 0;
    }
    int Message::setData(void *data, int len)
    {
        return 0;
    }
    int Message::setType()
    {
        return 0;
    }
    int Message::setMagic()
    {
        return 0;
    }

    MessageWorker::MessageWorker(int type)
    {
    }

    MessageWorker::~MessageWorker()
    {
    }

    int MessageWorker::dealMsg(void * buf,int len)
    {
        return 0;
    }

    MessageWorker::MessageWorker()
    {
    }

    int MessageMananger::registWorker(MessageWorker *pmw)
    {
        return 0;
    }

    int MessageMananger::run()
    {
        return 0;
    }
}
