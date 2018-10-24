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
#define MESSAGE_HEAD_LEN 10
Message::Message()
{
    const char *ptr = "IRST";
    memcpy(mMagic, ptr, 4);
    mType = 0;
    mLen = 0;
    mPtr = 0;
    PTHRAED_INIT(&mLocker);
}
Message::~Message()
{
    release();
}
void Message::release()
{
    PTHREAD_LOCK(&mLocker);
    if (mPtr)
    {
        free(mPtr);
    }
    mPtr = 0;
    mLen = 0;
    mType = 0;
    PTHREAD_UNLOCK(&mLocker);
}
int Message::writeHeader(void *buf, int size, char magic[],
                         unsigned int type, unsigned int dataLen)
{
    if (buf == 0 || size < MESSAGE_HEAD_LEN)
        return VAILD_LEN;
    memcpy(buf, magic, 4);
    char *ptr = (char *)buf;
    *(unsigned short *)(ptr + 4) = ntohs(type);
    *(unsigned int *)(ptr + 6) = ntohl(dataLen);
    return MESSAGE_HEAD_LEN;
}

int Message::readHeader(const void *buf, int size, char magic[],
                        unsigned int &type, unsigned int &dataLen)
{
    if (buf == 0 || size < MESSAGE_HEAD_LEN)
        return VAILD_LEN;
    memcpy(magic, buf, 4);
    memcpy((char *)&type, ((char *)buf) + 4, 2);
    memcpy((char *)&dataLen, ((char *)buf) + 6, 4);
    type = ntohs(type);
    dataLen = ntohl(dataLen);
    return MESSAGE_HEAD_LEN;
}
void *Message::getData()
{
    return mPtr;
}
int Message::getLen()
{
    return mLen;
}
int Message::getType()
{
    return mType;
}
string Message::getMagic()
{
    char buf[5] = {0};
    memcpy(buf, mMagic, 4);
    string str = buf;
    return str;
}
int Message::setData2Buffer(void *buf, int bufLen)
{
    PTHREAD_LOCK(&mLocker);
    if (buf == 0)
    {
        return VAILD_BUFFER;
    }
    if (bufLen < MESSAGE_HEAD_LEN + mLen)
    {
        return VAILD_LEN;
    }
    if (mPtr == 0)
    {
        return VAILD_DATA;
    }
    writeHeader(buf, bufLen, mMagic, mType, mLen);
    memcpy((char *)buf + MESSAGE_HEAD_LEN, mPtr, mLen);
    PTHREAD_UNLOCK(&mLocker);
    return MESSAGE_HEAD_LEN + mLen;
}
int Message::getDataFromBuffer(const void *buf, int bufLen)
{
    if (bufLen < MESSAGE_HEAD_LEN)
    {
        return VAILD_LEN;
    }
    char magic[4] = {0};
    unsigned int type = 0;
    unsigned int datalen = 0;
    int headLen = readHeader(buf, bufLen, magic, type, datalen);
    if (headLen < 0)
        return headLen;
    if (headLen != MESSAGE_HEAD_LEN)
        return VAILD_LEN;
    if (datalen == 0 || datalen > (100 << 20))
        return VAILD_LEN;
    memcpy(mMagic, magic, 4);
    mType = type;
    int ret = setData(((char *)buf) + MESSAGE_HEAD_LEN, datalen);
    if (ret >= 0)
        return MESSAGE_HEAD_LEN + mLen;
    else
        return ret;
}
int Message::setData(const void *data, int len)
{
    if (data == 0)
        return VAILD_DATA;
    if (len == 0)
        return VAILD_LEN;
    if (mLen != len)
    {
        if (mPtr)
            free(mPtr);
        mPtr = 0;
        mLen = 0;
    }
    if (mPtr == 0 && mLen == 0)
    {
        mPtr = malloc(len + 1);
        if (mPtr == 0)
        {
            return VAILD_ALLOC_FAIL;
        }
        memset(mPtr, 0, len + 1);
    }
    mLen = len;
    memcpy(mPtr, data, len);
    return SUCCESS;
}
int Message::setType(int type)
{
    mType = type;
    return SUCCESS;
}
int Message::setMagic(const char magic[4])
{
    memcpy(mMagic, magic, 4);
    return SUCCESS;
}

MessageWorker::MessageWorker(int type)
{
}

MessageWorker::~MessageWorker()
{
}

int MessageWorker::dealMsg(void *buf, int len)
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
} // namespace baseservice
