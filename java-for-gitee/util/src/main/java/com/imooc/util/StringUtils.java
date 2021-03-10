package com.imooc.util;

public class StringUtils {


    /**
     * 判断一个字符串是否为空，如果为空返回true，否则false
     * @param content
     * @return
     */

    public static boolean isEmpty(String content){

        return  null == content || "".equals(content);

    }

    /**
     * 判断一个字符串是否不为空，如果不为空返回true，否则false
     * @param content
     * @return
     */


    public static boolean isNotEmpty(String content){

        return  !isEmpty(content);

    }

}
