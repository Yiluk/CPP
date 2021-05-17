#include <iostream>
#include <cstdlib>
using namespace std;

enum color
{
	white, //1
	black, //2
	red,   //3
	blue = 20,
	orange //21
} c;

int main()
{
	cout << "\nmain func\n";

	//typedef可以为一个已有类型取一个新名字，例如下面语句，会告诉编译器，myint是int的另一个名称
	typedef int myint;
	myint a = 10;
	cout << a;

	cout << "\n";

	/*
		enum 枚举名 {
			标识符[=整型常数],
			标识符[=整型常数],
			...
			标识符[=整型常数]
		} 枚举变量;
	*/
	c = blue;
	cout << c;

	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单