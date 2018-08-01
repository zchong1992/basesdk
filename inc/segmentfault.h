
#ifndef __SEGMENTFAULT_H__
#define __SEGMENTFAULT_H__
#include "global.h"
#include "log.h"
namespace baseservice{
typedef struct thread_info_st
{
        char name[256];
        unsigned int tid;
}TIS;
typedef std::vector<TIS> TISL;
class znsegfault_catch
{
     public :
        static char handlesvaule[100][20];
        static void handle();
        static void catch_sign(void);
        static void no_print_seg_frame(int signal);
        static void print_seg_frame(int signal);
        static void setup_thread_info(unsigned int tid,const char *tname);
        static TIS getThreadInfo();
        static TISL m_thread_info; 

};



};
#endif 

