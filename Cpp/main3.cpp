#include <iostream>

//函数声明
int func();

int main()
{
	//函数调用
	int i = func();
}

//函数定义
int func()
{
	std::cout << "func" << std::endl;
	std::system("pause");
	return 0;
}