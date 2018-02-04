/*
 * FileName : AES.h
 * Get From GitHub and zc fix some error
 * eamil :zhengchong_china@163.com
 */
#ifndef __AES_H__
#define __AES_H__

#include "libbaseservice.h"
namespace baseservice
{
class AES  
{
public:
     AES(ZUINT1* key = NULL);
     virtual ~AES();
     void SetKey(ZUINT1 *key);
     ZUINT1* Cipher(ZUINT1* input, ZUINT1* output);
     ZUINT1* InvCipher(ZUINT1* input, ZUINT1* output);
     void* Cipher(void* input, void *output, int length=0);
     void* InvCipher(void* input,void *output, int length);

private:
     ZUINT1 Sbox[256];
     ZUINT1 InvSbox[256];
     ZUINT1 w[11][4][4];
     ZUINT1 FFmul_speed[256][256];

     void KeyExpansion(ZUINT1* key, ZUINT1 w[][4][4]);
     ZUINT1 FFmul(ZUINT1 a, ZUINT1 b);
     ZUINT1 FFmul_fast(ZUINT1 a, ZUINT1 b);
     void FFmul_init();

     void SubBytes(ZUINT1 state[][4]);
     void ShiftRows(ZUINT1 state[][4]);
     void MixColumns(ZUINT1 state[][4]);
     void AddRoundKey(ZUINT1 state[][4], ZUINT1 k[][4]);

     void InvSubBytes(ZUINT1 state[][4]);
     void InvShiftRows(ZUINT1 state[][4]);
     void InvMixColumns(ZUINT1 state[][4]);
};

enum AESMode_t { MODE_OFB = 1, MODE_CFB, MODE_CBC, MODE_ECB };
class AESModeOfOperation {
private:
     AES *m_aes;
     AESMode_t       m_mode;
     ZUINT1 m_key[16];
     ZUINT1 m_iv[16];
//     bool            m_firstround;
public:
     AESModeOfOperation();
     ~AESModeOfOperation();
     void set_mode(AESMode_t _mode);
     //AESMode_t get_mode();
     void set_key (ZUINT1 *key);
     void set_iv(ZUINT1 *iv);
     int  Encrypt(const ZUINT1 *input, int length, ZUINT1 *output);
     int  Decrypt(const ZUINT1 *input, int length, ZUINT1 *output);
};


}

#endif 
