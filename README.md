# cyy-2018-red-bag

这是cyy在2018年为大家准备的中国农历新年红包

（有人说这应该叫red envelope而不是red bag，然而我之前看别人这样写习惯了

回到正题，最初是我在博客上放了两个页面，给出挖了空的红包解密程序，并附上了说明。正如user.c/user.php中所示

v1版本中，我用"2018"的md5值（16进制文本）对密文进行异或加密。

v2版本中，我用"2018"的md5值（二进制，每两位作为一个字节）对密文进行异或加密。

详细的看代码吧~

答案在answer.c/answer.php中

祝大家狗年大吉！