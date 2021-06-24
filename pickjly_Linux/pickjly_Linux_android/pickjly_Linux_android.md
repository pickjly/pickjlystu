 <!-- Author : pickjly
 Email  : 2461789521@qq.com
 Date   : 2021-06-20
 Time   : 9:00
 File   : @pickjly_Linux_android.md
 Content:
      安卓架构 -->

# 了解安卓架构
        Google官方提供的经典分层架构图，从下往上依次分为Linux内核、HAL、系统Native库和Android运行时环境、Java框架层以及应用层这5层架构，其中每一层都包含大量的子模块或子系统。
## loader 层
        Rom：当手机处于关机状态时，长按Power键开机，引导芯片开始从固化在 ROM里的预设代码开始执行，然后加载引导程序到 RAM；
        loader：是安着启动之前的引导程序，主要是检查RAM，初始化硬件参数等功能。

## Linux 内核层