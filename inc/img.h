
#ifndef __IMG_H__
#define __IMG_H__

#include "global.h"
#include "log.h"

namespace baseservice{
     class zkznImg
    {
    public:
         static int jpeg2buf(UINT1 *dst,INT4 *buflen,UINT1 * inbuf,INT4 width ,INT4 height,INT4 channels,INT4 quality);
        
          static int  createbmpheader(unsigned char *buf,int *length,const int width,const int height,const int channels);
     };
}

#endif






