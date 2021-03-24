#!/bin/bash

# 可以将两个或者多个命令（程序或者进程）连接到一起，把一个命令的输出作为下一个命令的输入，
# 以这种方式连接的两个或者多个命令就形成了管道（pipe）。

:<<@
Linux 管道使用竖线|连接多个命令，这被称为管道符。Linux 管道的具体语法格式如下：
command1 | command2
command1 | command2 [ | commandN... ]
@

:<<@
假使需要将数据库备份，并且压缩，那么命令行输入是
# mysqldump -u root -p '123456' wiki > /tmp/wikidb.backup
# gzip -9 /tmp/wikidb.backup

使用管道是
# mysqldump -u root -p '123456' wiki | gzip -9

避免了创建 /tmp/wikidb.backup
@

:<<@
管道与重定向的区别：
管道是重定向到标准的输入输出
重定向是到文件本身
@