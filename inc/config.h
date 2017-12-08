
#ifndef __CONFIG_H__
#define __CONFIG_H__
#include "global.h"
#include "log.h"



namespace baseservice
{
    typedef  struct znconfigkv{
        std::string key;
        std::string value;
        struct znconfigkv *next;
        znconfigkv(){key="";value="";next=0;}
    }zkv;
    class znconfig
    {
    public:
        int loadfile(const char * finename);
        static znconfig* Getznconfig();
        int insertData(const char *,const char*);
        int print();
        void save(const char *path);
        int add(const char *key,const char* vlaue);
        int del(const char *key);
        const char * Getvalue(const char *key);
    private:
        zkv * m_zkv;
        znconfig();
        ~znconfig();
        static znconfig* m_znconfig;
    };
    

}
#endif 

