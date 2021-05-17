#include <iostream>

using namespace std;

//函数声明，传值调用、引用调用、指针调用
void swap1(int a, int b);
void swap2(int &a, int &b);
void swap3(int *a, int *b);

int main()
{
	//region 传值调用
	int a = 100;
	int b = 200;

	cout << "swap1 before,	a:" << a << endl;
	cout << "swap1 before,	b:" << b << endl;

	swap1(a, b);

	cout << "swap1 after,	a:" << a << endl;
	cout << "swap1 after,	b:" << b << endl;
	//endregion 传值调用

	//region 引用调用
	a = 100;
	b = 200;

	cout << "swap2 before,	a:" << a << endl;
	cout << "swap2 before,	b:" << b << endl;

	swap2(a, b);

	cout << "swap2 after,	a:" << a << endl;
	cout << "swap2 after,	b:" << b << endl;
	//endregion 引用调用

	//region 指针调用
	a = 100;
	b = 200;

	cout << "swap3 before,	a:" << a << endl;
	cout << "swap3 before,	b:" << b << endl;

	//&表示指向变量的指针，即变量的地址
	swap3(&a, &b);

	cout << "swap3 after,	a:" << a << endl;
	cout << "swap3 after,	b:" << b << endl;
	//endregion 指针调用

	bool bresult = [](int x, int y) { return x < y; };
	cout << "result:" << bresult << endl;
	auto aresult = [](int x, int y) -> int {int z = x + y; return z + x; };
	cout << "aresult:" << aresult << endl;
	/*
		[]      	       // 沒有定义任何变量。使用未定义变量会引发错误。
		[x, &y]       // x以传值方式传入（默认），y以引用方式传入。
		[&]           // 任何被使用到的外部变量都隐式地以引用方式加以引用。
		[=]          // 任何被使用到的外部变量都隐式地以传值方式加以引用。
		[&, x]     // x显式地以传值方式加以引用。其余变量以引用方式加以引用。
		[=, &z] // z显式地以引用方式加以引用。其余变量以传值方式加以引用。
	*/

	system("pause");
	return 0;
}

void swap1(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

void swap2(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

void swap3(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}