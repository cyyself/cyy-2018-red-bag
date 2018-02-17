<?php
    function decrypt($code,$key) {
        $codelen = strlen($code);
        $keylen = strlen($key);
        $ret = "";
        for ($i=0;$i<$codelen;$i++) {
            $ret .= $code[$i] ^  $key[$i%$keylen];
        }
        return $ret;
    }
    function a_cryptographic_hash_function($str) {
        return md5($str);
    }
    $encryptedbase64 = "W00dg9371baZ1L36horV0a3Dio+5gqOf0I/93ZmvVFlcUV5dVFYFAwMGAw==";
    $password = a_cryptographic_hash_function("2018");
    printf("Decrypted Data:%s\n",decrypt(base64_decode($encryptedbase64),$password));
    /*提示：
        1. 下划线保证填得下需要填的代码但可能会有很多多余空格。
        2. ^
        3. 对于Windows用户请注意charset为utf-8，不过不设置也不影响你提取出红包中的重要代码
        4. decrypt函数内部除了strlen外没有调用其它任何函数
    */
?>