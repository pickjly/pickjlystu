#include <stdio.h>
#include <stdarg.h>

// # 可变长参数函数 #
// C语言支持可变参长数函数(Variable Argument Functions)，即参数的个数可以是不定个
// 在函数定义的时候用(...)表示，比如我们常用的printf()\execl()函数等；printf函数的原型如下：
// int printf(const char *format, ...); // #至少需要一个普通的形参，比如上面代码中的*format，后面的省略号是函数原型的一部分。

// C语言定义了一系列宏来完成可变参数函数参数的读取和使用：
    // 宏va_start、va_arg、va_end
    // 在ANSI C标准下，这些宏定义在stdarg.h中。三个宏的原型如下
    // void va_start(va_list ap, last);// 取第一个可变参数（如上述printf中的i）的指针给ap，
    // last是函数声明中的最后一个固定参数（比如printf函数原型中的*fromat）；
    // type va_arg(va_list ap, type);	// 返回当前ap指向的可变参数的值，然后ap指向下一个可变参数；
    // 				// type表示当前可变参数的类型（支持的类型位int和double）；
    // void va_end(va_list ap);	// 将ap置为NULL

// int demo(char msg, ...) // 这个省略号代表可选参数。
// { 
// 	/*定义保存函数参数的结构*/
// 	va_list argp; 
// 	int argno = 0; 
// 	char para; 
// 	/*argp指向传入的第一个可选参数，msg是最后一个确定的参数*/ 
// 	va_start(argp, msg); 
// 	while (1)
// 	{
//         para = va_arg(argp, int); 
// 		// para = va_arg(argp, char); 
// //         简单的说，我们用va_arg(ap,type)取出一个参数的时候，
// // type绝对不能为以下类型：
// // ——char、signed char、unsigned char
// // ——short、unsigned short
// // ——signed short、short int、signed short int、unsigned short int
// // ——float

// 		if (strcmp(para, "") == 0) 
// 			break;
// 		printf("Parameter #%d is: %c\n", argno, para);
// 		argno++;
// 	}
// 	va_end(argp);
// }

double add( int n, ... )
{
  int i = 0;
  int sum = 0.0;
  va_list argptr;
  va_start( argptr, n );             // 初始化argptr
  for ( i = 0; i < n; ++i )       // 对每个可选参数，读取类型为double的参数，
    sum += va_arg( argptr, double ); // 然后累加到sum中
  va_end( argptr );
  return sum;
}

int main() {
    double sum = add(3, 1, 2, 3);
    printf(" sum is %f\n", sum);
}