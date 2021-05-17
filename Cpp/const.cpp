#include <iostream>

/*
	整数常量可以是八进制、十进制或十六进制的常量
	前缀指定基数：0 表示八进制，不带前缀则默认表示十进制，0x 或 0X 表示十六进制
	整数常量也可以带一个后缀，后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意
	212		 	   //合法十进制整数
	215u		  //合法十进制无符号整数
	0xFeeL 		 //合法十六进长整数
	078 	 	   //非法：8不为八进制整数
	033Uu 	    //非法：不能重复后缀

	85             // 十进制
	0213         // 八进制 
	0x4b         // 十六进制 
	30             // 整数 
	30u           // 无符号整数 
	30l            // 长整数 
	30ul          // 无符号长整数
	50Lu         // 无符号长整数
*/

/*
	字符常量是括在单引号中。如果常量以 L（仅当大写时）开头，则表示它是一个宽字符常量（例如 L'x'），此时它必须存储在 wchar_t 类型的变量中。
	否则，它就是一个窄字符常量（例如 'x'），此时它可以存储在 char 类型的简单变量中。
	字符常量可以是一个普通的字符（例如 'x'）、一个转义序列（例如 '\t'），或一个通用的字符（例如 '\u02C0'）。
*/

/*
	在 C++ 中，有两种简单的定义常量的方式：
	使用 #define 预处理器。
	使用 const 关键字。
*/

#define LENGTH 10
#define WIDTH 5
#define NAME "zx"

const int CONSTLENGTH = 10;
const int CONSTWIDTH = 5;
const char *CONSTNAME = "zhuxin";//指定字符串，在char变量名前加一个'*'符号

int main()
{
	int area1 = LENGTH * WIDTH;
	std::cout << area1 << std::endl;
	std::cout << NAME << std::endl;

	int area2 = CONSTLENGTH * CONSTWIDTH;
	std::cout << area2 << std::endl;
	std::cout << CONSTNAME << std::endl;

	std::system("pause");
}