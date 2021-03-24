# 告诉系统需要什么解释器
#!/bin/bash

# 用于输出
echo "Hello world"

# 定义变量，变量名与等号之间不能有空格
your_name="test_name"

# 除了显式地直接赋值，还可以用语句给变量赋值
# for file in 'ls /etc/'

# 使用变量，需要在变量名钱加上dollor符号
echo $your_name
echo ${your_name}

# 字符串可以用单引号，也可以用双引号，也可以不用引号。 推荐使用双引号
# 双引号可以有变量，可以出现转义字符

# 删除变量
test_var="test"
unset_test_var=`unset test_var`
if [ $unset_test_var==1 ];then
	echo "unset test_var success"
else
	echo "failed"
fi

# 拼接字符串
introduction="I am "
echo $introduction $your_name

# 获取字符串长度
string="runoob is a place where i can study sh"
echo "This string is about ${#string}"

# 提取子字符串
echo ${string:4:10}

# 查找子字符串
echo `expr index "$string" oob`

# 定义数组
# array1_name=(
# value0
# value1
# value2
# )
# 或者
# array2_name=(value0 value1 value2)

# 读取数组元素的值
# value_n = ${array_name[3]}

# 使用@符号可以获取数组的所有元素
array_test=(1 2 3)
echo ${array_test[@]}

# 取得数组元素的个数
length=${#array_test[@]}
echo "length is $length"
# 或者
length=${#array_test[*]}
echo "length is $length"
# 取得数组单个元素的长度
lengthn=${#array_test[2]}
echo "length of array_test[2] is $lengthn"

# 注释
:<<!
注释
!

:<<@
注释
@

:<<%
注释
%
