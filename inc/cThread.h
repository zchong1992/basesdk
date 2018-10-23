#ifndef __ZKHX_THREAD_H__
#define __ZKHX_THREAD_H__

#include "global.h"

class cThread
{
public:
    virtual ~cThread(){};
    cThread(){};
    virtual void start();
    virtual std::string getThreadName();
private:
    static void *startThread(void*);
    virtual int run()=0;
};

#endif