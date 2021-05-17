#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
	指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。就像其他变量或常量一样，您必须在使用指针存储其他变量地址之前，对其进行声明。

	星号是用来指定一个变量是指针。

	所有指针的值的实际数据类型，不管是整型、浮点型、字符型，还是其他的数据类型，都是一样的，都是一个代表内存地址的长的十六进制数。
	不同数据类型的指针之间唯一的不同是，指针所指向的变量或常量的数据类型不同。

	使用指针时会频繁进行以下几个操作：定义一个指针变量、把变量地址赋值给指针、访问指针变量中可用地址的值。这些是通过使用一元运算符 * 来返回位于操作数所指定地址的变量的值。

	指针是一个用数值表示的地址。因此，您可以对指针执行算术运算。可以对指针进行四种算术运算：++、--、+、-。

	(int *iptr; 使用iptr 与 *iptr的区别在于，不带星号访问变量得到的是内存地址，带星号访问得到的是内存地址存储的值)

	指针算术运算：
	假设 ptr 是一个指向地址 1000 的"整型"指针，是一个 32 位的整数，让我们对该指针执行算术运算：ptr++。
	在执行完运算之后，ptr 将指向位置 1004，因为 ptr 每增加一次，它都将指向下一个整数位置，即当前位置往后移 4 个字节。这个运算会在不影响内存位置中实际值的情况下，移动指针到下一个内存位置。
	如果 ptr 指向一个地址为 1000 的"字符"，上面的运算会导致指针指向位置 1001，因为下一个字符位置是在 1001。
	(指针运算其实就是指针存储的内存地址，加上这个指针类型的字节，例如：一个int类型的指针，存储的内存地址为0x79fddc，对指针做一次递增，等于内存地址后移4个字节，逢16进1，为0x79fde0)

	指针可以用关系运算符进行比较(比较内存地址大小--十六进制)，如 ==、< 和 >。如果 p1 和 p2 指向两个相关的变量，比如同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。

	数组开辟时内存是连续的，间隔为指定数组类型的字节数。例如：int iarr[3] = {10, 100, 1000}; [0] address = 0x79fdd8，[1] address = 0x79fddc，[2] address = 0x79fde0
	C++中函数是不能直接返回一个数组的，"但是数组其实就是指针"，所以可以让函数返回指针
	指针，即为地址，指针占几个字节跟语言无关，而是跟系统的寻址能力有关。
	例如：以前是 16 位地址，指针即为 2 个字节，现在一般是 32 位系统，所以是 4 个字节，以后 64 位，则就占 8 个字节。

	指向指针的指针：
	指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。
	指针的指针就是将指针的地址存放在另一个指针里面。
	通常，一个指针包含一个变量的地址。当我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。
	pointer					pointer				variable 指针1存储的地址为指针2的地址，指针2存储的地址去得到value
	address---------->address------->value
*/

void getmemaddress();							 //获取内存地址
void pointerpractice();							 //指针初练习
void nullpointer();								 //空指针
void pointervsarray();							 //指针vs数组
void pointerarray();							 //指针数组
void pointertopointer();						 //指向指针的指针
void passpointertofunction(unsigned long *lptr); //传递指针给函数
int *funcreturnptr();							 //从函数返回指针(这个方法做了生成和返回随机数)

int main()
{
	getmemaddress();
	pointerpractice();
	nullpointer();
	pointervsarray();
	pointerarray();
	pointertopointer();

	unsigned long l; //无符号长整型
	passpointertofunction(&l);
	cout << "passpointertofunction-->l variable:" << l << endl;
	cout << "----------------------------------------------------------------" << endl;

	int *p;
	p = funcreturnptr();
	for (int i = 0; i < 10; i++)
	{
		cout << "*(p + " << i << ") : " << *(p + i) << endl; //指针算术运算(=访问p[i]，一旦您把第一个元素的地址存储在 p 中，您就可以使用 *p、*(p+1)、*(p+2) 等来访问数组元素)
	}
	cout << "----------------------------------------------------------------" << endl;

	system("pause");
	return 0;
}

void getmemaddress()
{
	//访问内存地址
	int var1;
	char var2[10];
	cout << "var1Pointer:" << &var1 << endl;
	cout << "var2Pointer:" << &var2 << endl;
	cout << "----------------------------------------------------------------" << endl;
}

void pointerpractice()
{
	// int *ip;   //一个整型指针
	// float *fp; //一个单精度浮点型指针
	// char *cp;  //一个字符型指针

	int var = 20; //实际变量的声明
	int *ip;	  //指针变量的声明

	ip = &var; //在指针变量中存储var变量的地址

	cout << "Value of var variable:" << var << endl;

	//输出在指针变量中存储的地址
	cout << "Address stored in ip variable:" << ip << endl;

	//访问指针中地址的值
	cout << "Value of *ip variable:" << *ip << endl;
	cout << "----------------------------------------------------------------" << endl;
}

void nullpointer()
{
	int *ip = NULL;
	cout << "Address stored in ip variable:" << ip << endl; //输出0
	//空指针不能去访问地址的值(因为内存地址都没有)
	// cout << "Value of *ip variable:" << *ip << endl;
	/*
		在大多数的操作系统上，程序不允许访问地址为 0 的内存，因为该内存是操作系统保留的。
		然而，内存地址 0 有特别重要的意义，它表明该指针不指向一个可访问的内存位置。但按照惯例，如果指针包含空值（零值），则假定它不指向任何东西。
		如需检查一个空指针，您可以使用 if 语句：		if(ptr)
	*/
	cout << "----------------------------------------------------------------" << endl;
}

void pointervsarray()
{
	//递增一个指针
	int iarr[3] = {10, 100, 1000};
	int *iptr;
	//指针中的数组地址(等于数组时，默认存储数组的第一个元素的地址)
	iptr = iarr;
	for (int i = 0; i < 4; i++)
	{
		cout << "iptr Address of value[" << i << "] = " << iptr << endl; // 0x79fdd8 0x79fddc 0x79fde0  0x79fde4 (16进制逢16进1,a=10 b=11 c=12 d=13 e=14 f=15 g =16，f最大，到了g就会进一位)
		cout << "iptr Value of value[" << i << "] = " << *iptr << endl;  //10 100 1000 3
		iptr++;
	}
	cout << "----------------------------------------------------------------" << endl;

	//递减一个指针
	string sarr[] = {"zx", "zhux", "zhuxin"};
	string *sptr;
	int sarrsize = sizeof(sarr) / sizeof(sarr[0]); //sarr在内存中的大小/sarr[0]在内存中的大小得到数组的大小
	//指针中最后一个元素的地址
	sptr = &sarr[sarrsize - 1]; //(为什么此处要使用&？因为这里访问数组中最后一个元素，得到的是一个string类型的值，通过&得到这个值的内存地址给到指针，而如果直接赋值数组的话，得到的是数组的第一个索引的值的内存地址，以为数组指针是可以互换的)
	for (int i = 0; i < sarrsize; i++)
	{
		cout << "sptr Address of value[" << i << "] = " << sptr << endl; //0x79fd80 0x79fd60 0x79fd40 (string类型指针存储数组，不能做算术运算超出范围)
		cout << "sptr Value of value[" << i << "] = " << *sptr << endl;  //zhuxin zhux zx
		sptr--;
	}
	cout << "----------------------------------------------------------------" << endl;

	//指针比较
	int var[3] = {10, 100, 200};
	int *ptr;
	int varsize = sizeof(var) / sizeof(var[0]);
	// 指针中第一个元素的地址
	ptr = var;
	int i = 0;
	while (ptr <= &var[varsize - 1])
	{
		cout << "Address of var[" << i << "] = ";
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;

		ptr++;
		i++;
	}
	cout << "----------------------------------------------------------------" << endl;
}

void pointerarray()
{
	int arrayLength = 3;
	int iarr[arrayLength] = {10, 100, 1000};
	int *iptrarr[arrayLength]; /*整数指针数组(由3个整数指针组成的数组)*/
	for (int i = 0; i < arrayLength; i++)
	{
		iptrarr[i] = &iarr[i];
	}
	for (int i = 0; i < arrayLength; i++)
	{
		cout << "iptrarr Address of value[" << i << "] = " << iptrarr[i] << endl;
		cout << "iptrarr Value of value[" << i << "] = " << *iptrarr[i] << endl;
	}
	cout << "----------------------------------------------------------------" << endl;

	int *iptrarr2[arrayLength]{&iarr[0], &iarr[1], &iarr[2]};
	for (int i = 0; i < arrayLength; i++)
	{
		cout << "iptrarr2 Address of value[" << i << "] = " << iptrarr2[i] << endl;
		cout << "iptrarr2 Value of value[" << i << "] = " << *iptrarr2[i] << endl;
	}
	cout << "----------------------------------------------------------------" << endl;

	//也可以用一个指向“字符的指针数组”来存储一个“字符串列表”
	const char *name[arrayLength]{"1zhuxin", "2zhuyong", "3zhujing"};
	for (int i = 0; i < arrayLength; i++)
	{
		/*
			C++ 中，将 char * 或 char[] 传递给 cout 进行输出，结果会是整个字符串，如果想要获得字符串的地址（第一个字符的内存地址），可使用以下方法：
			强制转化为其他指针（非 char*）。可以是 void *，int *，float *， double * 等。* 使用 &s[0] 不能输出 s[0]（首字符）的地址。
			因为 &s[0] 将返回 char*，对于 char*（char 指针），cout 会将其作为字符串来处理，向下查找字符并输出直到字符结束 *。
		*/
		cout << "name Address of value[" << i << "] = " << (int *)name[i] << endl;
		cout << "name Value of value *(name + " << i << ") : " << *(name + i) << endl;
		cout << "name Value of value name[" << i << "] : " << name[i] << endl;
		cout << "zzzzzz[" << i << "] : " << *name[i] << endl;
	}
	cout << "----------------------------------------------------------------" << endl;
}

void pointertopointer()
{
	/*
		// 一个指向指针的指针变量声明，即在变量名前放置两个星号。
		int i;
		int *iptr;
		int **iptrtoptr; //一个指向int类型指针的指针
		i = 5201314;
		iptr = &i;		   //获取i的地址
		iptrtoptr = &iptr; //获取iptr的地址
		cout << "i Address = " << &i << endl;
		cout << "i Value = " << i << endl;
		cout << "iptr Address = " << &iptr << endl;
		cout << "iptr Save Address = " << iptr << endl;
		cout << "iptr Value = " << *iptr << endl;
		cout << "iptrtoptr Address = " << &iptrtoptr << endl;
		cout << "iptrtoptr Save Address = " << iptrtoptr << endl;
		cout << "iptrtoptr Value = " << **iptrtoptr << endl; //一个*得到的是iptr存储的内存地址：0x79fdec，两个*得到的是iptr存储的内存地址的值：5201314
		cout << "----------------------------------------------------------------" << endl;
	*/

	int i;
	int *iptr;
	int **iptrtoptr;
	int ***iptrtoptrtoptr;
	int ****iptrtoptrtoptrtoptr;
	i = 5201314;
	iptr = &i;
	iptrtoptr = &iptr;
	iptrtoptrtoptr = &iptrtoptr;
	iptrtoptrtoptrtoptr = &iptrtoptrtoptr;

	cout << "i Address = " << &i << endl;
	cout << "i Value = " << i << endl;

	cout << "iptr Address = " << &iptr << endl;
	cout << "iptr Save Address = " << iptr << endl;
	cout << "iptr Value = " << *iptr << endl;

	cout << "iptrtoptr Address = " << &iptrtoptr << endl;
	cout << "iptrtoptr Save Address = " << iptrtoptr << endl;
	cout << "iptrtoptr Value = " << **iptrtoptr << endl;

	cout << "iptrtoptrtoptr Address = " << &iptrtoptrtoptr << endl;
	cout << "iptrtoptrtoptr Save Address = " << iptrtoptrtoptr << endl;
	cout << "iptrtoptrtoptr Value = " << ***iptrtoptrtoptr << endl;

	cout << "iptrtoptrtoptrtoptr Address = " << &iptrtoptrtoptrtoptr << endl;
	cout << "iptrtoptrtoptrtoptr Save Address = " << iptrtoptrtoptrtoptr << endl;
	cout << "iptrtoptrtoptrtoptr* Value = " << *iptrtoptrtoptrtoptr << endl;
	cout << "iptrtoptrtoptrtoptr** Value = " << **iptrtoptrtoptrtoptr << endl;
	cout << "iptrtoptrtoptrtoptr*** Value = " << ***iptrtoptrtoptrtoptr << endl;
	cout << "iptrtoptrtoptrtoptr**** Value = " << ****iptrtoptrtoptrtoptr << endl;

	/*
		i Address = 0x79fdec
		i Value = 5201314
		iptr Address = 0x79fde0
		iptr Save Address = 0x79fdec
		iptr Value = 5201314
		iptrtoptr Address = 0x79fdd8
		iptrtoptr Save Address = 0x79fde0
		iptrtoptr Value = 5201314
		iptrtoptrtoptr Address = 0x79fdd0
		iptrtoptrtoptr Save Address = 0x79fdd8
		iptrtoptrtoptr Value = 5201314
		iptrtoptrtoptrtoptr Address = 0x79fdc8
		iptrtoptrtoptrtoptr Save Address = 0x79fdd0
		iptrtoptrtoptrtoptr* Value = 0x79fdd8
		iptrtoptrtoptrtoptr** Value = 0x79fde0
		iptrtoptrtoptrtoptr*** Value = 0x79fdec
		iptrtoptrtoptrtoptr**** Value = 5201314
	*/

	//声明的几重指针，那么取值的时候就要写几个*，比如一个4重指针，写一个*表示获取上一重指针所存储的内存地址(第三重)，写两个*表示获取上上重指针所存储的内存地址(第二重)
	//写三个*表示获取上上上重指针所存储的内存地址(第一重)，写四个*就直接得到第一重指针存储的内存地址的值了，没有更上一重了
	cout << "----------------------------------------------------------------" << endl;
}

void passpointertofunction(unsigned long *lptr)
{
	//直接访问*指针相当于得到指针存储的内存地址所指向的内存区域，去修改区域中的值
	*lptr = time(NULL);
}

int *funcreturnptr()
{
	//C++不支持在函数外返回局部变量的地址，除非定义局部变量为static变量。
	static int iarr[10];

	//设置随机数种子
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		iarr[i] = rand();
	}
	return iarr; //使用表示指针的数组名（即第一个数组元素的地址）来返回它们
}