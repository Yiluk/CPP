#include <iostream>

//变量声明
extern int ia, ib, ic;
extern float fa, fb, fc;
extern bool bb;

int main()
{
	//变量定义
	int ia, ib, ic;
	float fa, fb, fc;
	bool bb;
	//实际初始化
	ia = 10, ib = 20, ic = 30;
	fa = 1.1, fb = 1.2, fc = 1.3;
	bb = true;
	std::cout << ia << std::endl;
	std::cout << fc << std::endl;
	std::cout << bb << std::endl; //true打印为1，false打印为0
	std::system("pause");
	return 0;
}