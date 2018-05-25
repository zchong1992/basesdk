#ifndef __BASE64_H__
#define __BASE64_H__


#include <stdio.h>
#include <string.h>
#include "global.h"
namespace baseservice{
extern int base64encode(void *out, void *in, int length);
extern int base64decode(void *out, void *in, int length);
}


#endif 
