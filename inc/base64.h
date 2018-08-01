#ifndef __BASE64_H__
#define __BASE64_H__


#include <stdio.h>
#include <string.h>
namespace baseservice{
extern int base64encode(unsigned char *out, unsigned char *in, int length);
extern int base64decode(unsigned char *out, unsigned char *in, int length);
extern void inittable();
}


#endif 
