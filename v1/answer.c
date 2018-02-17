#include <stdio.h>
#include <string.h>
char *decrypt(char *code,char *key) {
    int codelen = strlen(code);
    int keylen = strlen(key);
    char *ret = (char*)malloc(codelen+1);
    //for c++: char *ret= new char[codelen+1];
    ret[codelen] = 0;
    for (int i=0;i<codelen;i++) {
        ret[i] = code[i] ^  key[i%keylen];
    }
    return ret;
}
int main() {
    char *encrypteddata = "\x5b\x4d\x1d\x83\xdd\xfb\xd5\xb6\x99\xd4\xbd\xfa\x86\x8a\xd5\xd1\xad\xc3\x8a\x8f\xb9\x82\xa3\x9f\xd0\x8f\xfd\xdd\x99\xaf\x54\x59\x5c\x51\x5e\x5d\x54\x56\x05\x03\x03\x06\x03";
    char *password = "84ddfb34126fc3a48ee38d7044e87276";//尝试从别的地方获得"2018"的某种摘要hash算法加密后的值
    printf("Decrypted Data:%s\n",decrypt(encrypteddata,password));
    /*提示：
        1. 下划线保证填得下需要填的代码但可能会有很多多余空格。
        2. ^
        3. 对于Windows用户请注意charset为utf-8，不过不设置也不影响你提取出红包中的重要代码
        4. decrypt函数内部除了strlen外没有调用其它任何函数
    */
    return 0;
}