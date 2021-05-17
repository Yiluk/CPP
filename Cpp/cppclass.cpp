#include <iostream>

using namespace std;

/*
	范围解析运算符 ::
	类的析构函数是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。
	析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
*/

class Box
{
private:
	double length;	//长
	double breadth; //宽
	double heigth;	//高
	int *iptr;

public:
	//构造函数声明
	Box();
	Box(double length, double breadth, double heigth);
	//析构函数声明
	~Box();
	//成员函数声明
	double get();
	void set(double length, double breadth, double heigth);
	int getPtrLen();
};

Box::Box()
{
	cout << "No parameters structure function" << endl;
}

// 使用初始化列表初始化字段，下面注释的写法相当于省略掉了3行this->赋值语句
// Box::Box(double length, double breadth, double heigth) : length(length), breadth(breadth), heigth(heigth)
Box::Box(double length, double breadth, double heigth)
{
	cout << "parameters structure function" << endl;
	this->length = length;
	this->breadth = breadth;
	this->heigth = heigth;
}

Box::~Box()
{
	cout << "destruct function" << endl;
}

double Box::get()
{
	return this->length * this->breadth * this->heigth;
}

void Box::set(double length, double breadth, double heigth)
{
	this->length = length;
	this->breadth = breadth;
	this->heigth = heigth;
}

int main()
{
	//声明Box类型变量时就默认调用了无参构造函数
	Box Box1;
	Box Box2(10.0, 13.0, 14.0); //带参构造函数
	double volume = 0.0;		//体积

	Box1.set(6.0, 2.0, 12.5);
	volume = Box1.get();
	cout << "Box1 volume:" << volume << endl;

	volume = Box2.get();
	cout << "Box2 volume:" << volume << endl;
	return 0;
}