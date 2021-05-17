#include <iostream>

using namespace std;

/*
	引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。

	引用与指针的区别：
	不存在空引用。引用必须连接到一块合法的内存。
	一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
	引用必须在创建时被初始化。指针可以在任何时间被初始化。
*/

double dvals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double &setValues(int i)
{
	double &ref = dvals[i];
	return ref; //返回第i个元素的引用，ref是一个引用变量，ref引用dvals[i]，最后再返回
}

double *setValues_p(int i)
{
	return &dvals[i];
}

int main()
{
	//声明变量
	int i;
	double d;

	//声明引用变量
	int &ri = i;	// "ri 是一个初始化为 i 的整型引用"
	double &rd = d; // "rd 是一个初始化为 d 的双精度浮点型引用"

	i = 5;
	cout << "Value of i : " << i << endl;
	cout << "Value of i reference : " << ri << endl;

	d = 11.7;
	cout << "Value of d : " << d << endl;
	cout << "Value of d reference : " << rd << endl;
	cout << "----------------------------------------------------------------" << endl;

	cout << "change dvals before:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "dvals[" << i << "] = ";
		cout << dvals[i] << endl;
	}

	setValues(1) = 20.666;
	setValues(3) = 70.888;
	*setValues_p(4) = 99.999;

	cout << "change dvals after:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "dvals[" << i << "] = ";
		cout << dvals[i] << endl;
	}

	system("pause");
	return 0;
}