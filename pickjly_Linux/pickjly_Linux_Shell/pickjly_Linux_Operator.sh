#!/bin/bash

# /***
#  * Author : pickjly
#  * Email  : 2461789521@qq.com
#  * Date   : 2021-05-11
#  * Time   : 23:00
#  * File   : @pickjly_Linux_Operator.sh
#  * Content:
#  *      运算符
#  * ***/

:<<@
Shell 和其他编程语言一样，支持多种运算符，包括：

    算数运算符
    关系运算符
    布尔运算符
    字符串运算符
    文件测试运算符
@

# 加法
var1=1
var2=2
val=`expr $var1 + $var2`
echo "$var1 + $var2 = $val"

# 减法
var1=1
var2=2
val=`expr $var1 - $var2`
echo "$var1 - $var2 = $val"

# 乘法
var1=1
var2=2
val=`expr $var1 \* $var2`
echo "$var1 * $var2 = $val"

# 除法
var1=1
var2=2
val=`expr $var1 / $var2`
echo "$var1 / $var2 = $val"

if [ $var1 == $var2 ];then
	echo "var1 == var2"
fi
if [ $var1 != $var2 ];then
	echo "var1 != var2"
fi

:<<@
-b file 	检测文件是否是块设备文件，如果是，则返回 true。 	[ -b $file ] 返回 false。
-c file 	检测文件是否是字符设备文件，如果是，则返回 true。 	[ -c $file ] 返回 false。
-d file 	检测文件是否是目录，如果是，则返回 true。 	[ -d $file ] 返回 false。
-f file 	检测文件是否是普通文件（既不是目录，也不是设备文件），如果是，则返回 true。 	[ -f $file ] 返回 true。
-p file 	检测文件是否是有名管道，如果是，则返回 true。 	[ -p $file ] 返回 false。
-r file 	检测文件是否可读，如果是，则返回 true。 	[ -r $file ] 返回 true。
-w file 	检测文件是否可写，如果是，则返回 true。 	[ -w $file ] 返回 true。
-x file 	检测文件是否可执行，如果是，则返回 true。 	[ -x $file ] 返回 true。
-s file 	检测文件是否为空（文件大小是否大于0），不为空返回 true。 	[ -s $file ] 返回 true。
-e file 	检测文件（包括目录）是否存在，如果是，则返回 true。 	[ -e $file ] 返回 true。
     -S: 判断某文件是否 socket。
    -L: 检测文件是否存在并且是一个符号链接。 
@
file="./test.sh"
if [ -e $file ];then
	if [ -r $file ]
	then
	   echo "文件可读"
	else
	   echo "文件不可读"
	fi
else
	echo "file not exist"
fi
