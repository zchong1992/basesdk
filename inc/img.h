
#ifndef __IMG_H__
#define __IMG_H__

#include "global.h"
#include "log.h"

namespace baseservice{
     class zkznImg
    {
    public:
         static int jpeg2buf(ZUINT1 *dst,ZINT4 *buflen,ZUINT1 * inbuf,ZINT4 width ,ZINT4 height,ZINT4 channels,ZINT4 quality);
        
          static int  createbmpheader(unsigned char *buf,int *length,const int width,const int height,const int channels);
     };
}

#endif






