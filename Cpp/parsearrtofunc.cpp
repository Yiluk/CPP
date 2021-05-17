#include <iostream>

using namespace std;

/*
	C++中函数是不能直接返回一个数组的，"但是数组其实就是指针"，所以可以让函数返回指针

	C++ 中您可以通过指定不带索引的数组名来传递一个指向数组的指针。
	C++ 传数组给一个函数，数组类型自动转换为指针类型，因而传的实际是地址。
*/

double getAverage(int *arr, int size); //形参为一个指针
double getAverage(int arr[5]);		   //形参为一个已定义大小的数组
double getAverage2(int arr[]);		   //形参为一个未定义大小的数组

int main(int argc, char const *argv[])
{
	// 带有 5 个元素的整型数组
	int balance[5] = {1000, 2, 3, 17, 50};
	int *pt1 = balance;
	// 分别计算数组元素个数，以及整型指针的字节数
	size_t balance_size = sizeof(balance) / sizeof(int);
	size_t pt1_size = sizeof(pt1);

	double avg, avg2, avg3;

	cout << "array size : " << balance_size << endl;
	cout << "pt1_size : " << pt1_size << endl;

	avg = getAverage(balance, 5);
	avg2 = getAverage(balance);
	avg3 = getAverage2(balance);

	// 输出返回值
	cout << "getAverage(int *arr, int size):" << avg << endl;
	cout << "getAverage(int arr[5]):" << avg2 << endl;
	cout << "getAverage2(int arr[]):" << avg3 << endl;

	system("pause");
	return 0;
}

double getAverage(int *arr, int size)
{
	int i, sum = 0;
	double avg;
	// 打印第一个形参的字节数
	cout << "Inside getAverage(int *arr, int size) sizeof(arr) = " << sizeof(arr) << endl;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = double(sum) / size;
	return avg;
}

double getAverage(int arr[5])
{
	int i, sum = 0, size = 5;
	double avg;
	// 打印第一个形参的字节数
	cout << "Inside getAverage(int arr[5]) sizeof(arr) = " << sizeof((int *)arr) << endl;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = double(sum) / size;
	return avg;
}

double getAverage2(int arr[])
{
	int i, sum = 0, size = 5;
	double avg;
	// 打印第一个形参的字节数
	cout << "Inside getAverage2(int arr[]) sizeof(arr) = " << sizeof((int *)arr) << endl;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = double(sum) / size;
	return avg;
}