Linux内核只是Linux操作系统一部分。对下，它管理系统的所有硬件设备；对上，它通过系统调用，向Library Routine（例如C库）或者其它应用程序提供接口。

## Linux 内核的整体架构

- Process Scheduler

   也称作进程管理、进程调度。负责管理CPU资源，以便让各个进程可以以尽量公平的方式访问CPU。

- Memory Manager

   内存管理。负责管理Memory（内存）资源，以便让各个进程可以安全地共享机器的内存资源。另外，内存管理会提供虚拟内存的机制，该机制可以让进程使用多于系统可用Memory的内存，不用的内存会通过文件系统保存在外部非易失存储器中，需要使用的时候，再取回到内存中。

- VFS（Virtual File System）

   虚拟文件系统。Linux内核将不同功能的外部设备，例如Disk设备（硬盘、磁盘、NAND Flash、Nor Flash等）、输入输出设备、显示设备等等，抽象为可以通过统一的文件操作接口（open、close、read、write等）来访问。这就是Linux系统“一切皆是文件”的体现（其实Linux做的并不彻底，因为CPU、内存、网络等还不是文件，如果真的需要一切皆是文件，还得看贝尔实验室正在开发的"Plan 9”的）。

- Network
   网络子系统。负责管理系统的网络设备，并实现多种多样的网络标准。

- IPC（Inter-Process Communication）
   进程间通信。IPC不管理任何的硬件，它主要负责Linux系统中进程之间的通信。

## 内核的设计流派

- 单内核

    单一的体系结构，所有的功能集成在内核中， 方便不同功能之间进行通信，

- 微内核

    将各种功能分拆成不同的内核子系统， 子系统之间必须设计高效的通信机制

## 内核谈论

- Linux是不是微内核

    早期的Linux没有微内核的设计思想。后来，尽管微内核的设计思想出现，Linus也没有将之修改为微内核，因为彼时的微内核并不比单内核要高效，所以没有特地修改为微内核。

    不过Linux内核发展中，吸取了微内核的设计经验，使用了模块化设计，使Linux内核兼具微内核的特性。

    Linux的模块化设计，由核心的外围功能模块组成内核。Linux其他的功能模块必以来内核。在使用时，进行装载，不使用时动态卸载。Linux下的模块外在表现为类型程序库文件(.so), 内核模块为(.ko, kernel object)。

- Windows是什么类型的？
   Windows将是微内核的操作系统

## 进程管理

- 进程简介

   进程是正在执行的程序，同时也是操作系统进行资源管理的最小单位。Linux系统中通常通过fork()创建一个新的进程，通过exec函数族来载入新的程序执行（一般在fork了一个新进程之后调用），通过exit()退出执行。

- 进程描述符 - task_struct

   一个进程的所有信息保存在进程描述符里面， 内核使用双向链表来存储所有进程的文件描述符。
   task_struct 是一个非常大的结构体， 包括进程号、打开的文件、进程的地址空间、挂起的信号、进程状态等。

- 进程状态
  - Task_Running
  - Task_Interruptible
  - Task_UnInterruptible
  - Task_Stoped
  - Task_Traced
  - Exit_ZomBie
  - Exit_Dead

## 虚拟文件系统

- VFS简介

   让用户空间的程序不用管文件系统的格式和类型从而进行统一的操作，所以这样说VFS就是文件操作的适配器。

- 通用文件模型

   VFS通过通用文件模型来对文件系统进行描述，这个模型要求具有一般性，能够反映大多数文件系统的存储结构。

   - 超级块对象（supe_ block）：此对象描述文件系统有关信息,例如文件系统类型，根目录，块大小等。

   - 索引节点对象（inode）：此对象描述文件的具体信息，例如文件类型以及大小，存储位置等。
   - 目录项对象（dentry）：组成用户可见的目录树的主要结构，保存了当前文件文件名，父目录项等，注意目录项不一定是目录，所有的文件都可以通过目录项对象来表示。
   - 文件对象（file）：此对象对应于用户空间的File结构体，用于保存用户进行文件操作的相关参数，例如当前操作位置（偏移量），打开权限，文件所属用户ID等等。

- 数据结构

   - 超级块
   ```
   struct super_block{
   .....
   struct list_head s_list; //超级块链表
   dev_t s_dev;//设备标识符
   unsigned long s_blocksize;//以字节为单位的块大小
   struct file_system_type *s_type;//文件系统类型
   struct dentry * s_root;//文件系统根目录目录项
   struct list_head s_inodes;//所有索引节点链表
   struct list_head s_files;//文件对象链表。

   struct super_operations *s_op;//超级块方法（成员方法）
   }
   ```
   - 索引节点
   ```
   struct inode{
   .....
   struct list_head i_list;//索引节点链表
   struct super_block * i_sb;//此节点对应超级块
   structlist_head i_dentry;//引用此索引节点的目录项链表
   loff_t i_size;//文件字节数

   struct inode_operations *i_op;//索引节点操作方法文件（成员方法）
   }
   ```
   - 目录项
   ```
   struct dentry{
   ......
   struct dentry * d_parent;//父目录的目录项
   struct qstr d_name;//文件名
   struct list_head d_subdirs;//目录项是目录时，子目录的目录项链表
   struct super_block *d_sb;//文件的超级块对象
   struct inode * d_inode;//该目录项对应的索引节点

   struct dentry_operations * d_op;//目录项方法（成员方法）
   }
   ```
   - 文件对象
   ```
   struct file{
   ......
   struct dentry *f_dentry;//文件的目录项对象
   unsigned int f_flags;//打开文件指示的标志
   unsigned int f_uid;//用户uid
   loff_t f_pos;//当前文件位置位移量
   struct vfsmount *f_vfsmnt;//改文件所处的文件系统

   struct file_operations *f_op;//文件操作方法（成员方法）
   }
   ```
- 交互对象

   VFS只是一层设计框架，具体的操作动作一般都通过其他对象读出来。VFS上层是用户层，下层是文件系统，再下层是硬件驱动，存储硬件。