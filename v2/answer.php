<?php
    function hextobin($str) {
        $ret = "";
        for ($i=0;$i<32;$i += 2) {
            $ret .= chr(hexdec($str[$i].$str[$i+1]));
        }
        return $ret;
    }
    function a_cryptographic_hash_function($str) {
        return md5($str);
    }
    function decrypt($code,$key) {
        $codelen = strlen($code);
        $keylen = strlen($key);
        $ret = "";
        for ($i=0;$i<$codelen;$i++) {
            $ret .= $code[$i] ^  $key[$i%$keylen];
        }
        return $ret;
    }
    $encrypteddata = base64_decode("56SC06n2JSYmBQbsoVHGkxF7FIiTiVcLalgVlep1ERnguMEGIVjzk7vXuA==");
    $key = hextobin(a_cryptographic_hash_function("2018"));
    printf("Decrypted Data:%s\n",decrypt($encrypteddata,$key));
    /*提示：
        1. 下划线保证填得下需要填的代码但可能会有很多多余空格。
        2. ^ ^
        3. 对于Windows用户请注意charset为utf-8，不过不设置也不影响你提取出红包中的重要代码
        4. decrypt函数内部除了strlen外没有调用其它任何函数
    */
?>