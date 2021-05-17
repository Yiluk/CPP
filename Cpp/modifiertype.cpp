#include <iostream>

/*
	数据类型修饰符：
	signed（有符号），表明该类型是有符号数，和 unsigned 相反。数字类型（整型和浮点型）都可以用 signed 修饰。但默认就是 signed，所以一般不会显式使用。
	unsigned	(无符号），表明该类型是无符号数
	long （长整数）
	short （短整数）

	修饰符 signed、unsigned、long、short 可应用于整型，signed 和 unsigned 可应用于字符型，long 可应用于双精度型。
	修饰符 signed 和 unsigned 也可以作为 long 或 short 修饰符的前缀。例如：unsigned long int。
*/

/*
	C++ 中的类型限定符：
	const	const 类型的对象在程序执行期间不能被修改改变。
	volatile	修饰符 volatile 告诉编译器不需要优化volatile声明的变量，让程序可以直接从内存中读取变量。对于一般的变量编译器会对变量进行优化，将内存中的变量值放在寄存器中以加快读写效率。
	restrict	由 restrict 修饰的指针是唯一一种访问它所指向的对象的方式
*/

//C++ 允许使用速记符号来声明无符号短整数或无符号长整数。您可以不写 int，只写单词 unsigned、short 或 unsigned、long，int 是隐含的。例如，下面的两个语句都声明了无符号整型变量。
unsigned x;
unsigned int y;

int main()
{
	short int i;		  //有符号短整数
	short unsigned int j; //无符号短整数

	j = 50000;
	i = j;
	std::cout << i << "\t" << j << std::endl;// i = -15536 	j = 50000 无符号短整数 50,000 的位模式被解释为有符号短整数 -15,536
	std::system("pause");
}
