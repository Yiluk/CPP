#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1 = "str1";
	string str2 = "str2";
	string str3;
	int length;
	str3 = str1;
	cout << "str3:" << str3 << endl;
	str3 = str1 + str2;
	cout << "str3(str1+str2):" << str3 << endl;
	cout << "str3(length):" << str3.size() << endl;
	cout << "str1:" << str1 << endl;
	system("pause");
	return 0;
}