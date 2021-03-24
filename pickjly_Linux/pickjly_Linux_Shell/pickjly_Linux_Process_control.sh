#!/bin/bash

a=20

# if
if [ $a -gt 10 ];then
	echo "a is bigger than 10"
fi

a=5
# if else
if [ $a -gt 10 ];then
	echo "a is bigger than 10"
else
	echo "a is less than 10"
fi

# if elif else
a=15
if [ $a -gt 20 ];then
	echo "a is bigger than 20"
elif [ $a -lt 10 ];then
	echo "a is less than 10"
else
	echo "a is bigger than 10 and less than 20"
fi

# for
var_array=(1 2 3 4 5 6 7 8 9 10);
for var_loop in ${var_array[@]}
do
	echo "var_loop is $var_loop"
done

# while
var_loop=1;
# while [ $var_loop -le 10 ] 
while (( $var_loop <= 10 ))
do
	echo "var_loop is $var_loop"
	let "var_loop++"
done

# case
echo '输入 1 到 4 之间的数字:'
echo '你输入的数字为:'
read aNum
case $aNum in
    1)  echo '你选择了 1'
    ;;
    2)  echo '你选择了 2'
    ;;
    3)  echo '你选择了 3'
    ;;
    4)  echo '你选择了 4'
    ;;
    *)  echo '你没有输入 1 到 4 之间的数字'
    ;;
esac

# break; continue
