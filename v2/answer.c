#include <stdio.h>
#include <string.h>
char *decrypt(char *code,char *key,int codelen,int keylen) {
    char *ret = (char*)malloc(codelen+1);
    //for c++: char *ret= new char[codelen+1];
    ret[codelen] = 0;
    for (int i=0;i<codelen;i++) {
        ret[i] = code[i] ^  key[i%keylen];
    }
    return ret;
}
int main() {
    char *encrypteddata = "\xe7\xa4\x82\xd3\xa9\xf6\x25\x26\x26\x5\x6\xec\xa1\x51\xc6\x93\x11\x7b\x14\x88\x93\x89\x57\xb\x6a\x58\x15\x95\xea\x75\x11\x19\xe0\xb8\xc1\x6\x21\x58\xf3\x93\xbb\xd7\xb8";
    char *key = "\x84\xdd\xfb\x34\x12\x6f\xc3\xa4\x8e\xe3\x8d\x70\x44\xe8\x72\x76";//用某种摘要hash算法加密的"2018"的二进制值，每8位压成一个char
    printf("Decrypted Data:%s\n",decrypt(encrypteddata,key,43,16));
    /*提示：
        1. 下划线保证填得下需要填的代码但可能会有很多多余空格。
        2. ^ ^
        3. 对于Windows用户请注意charset为utf-8，不过不设置也不影响你提取出红包中的重要代码
        4. decrypt函数内部除了strlen外没有调用其它任何函数
    */
    return 0;
}