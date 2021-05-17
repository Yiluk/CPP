#include <string>
#include <iostream>

using namespace std;

void printbooks(struct Books Books);
void printbooks_p(struct Books *Books);

struct Books
{
	int book_id;
	string title;
	string author;
	string content;
};

int main()
{
	Books Book1;
	Book1.book_id = 1;
	Book1.title = "Book1";
	Book1.author = "zhuxin";
	Book1.content = "Book1Content";

	Books Book2;
	Book2.book_id = 2;
	Book2.title = "Book2";
	Book2.author = "zhuyong";
	Book2.content = "Book2Content";

	printbooks(Book1);
	printbooks(Book2);

	struct Books *Book_p = &Book1;
	printbooks_p(Book_p);

	system("pause");
	return 0;
}

void printbooks(struct Books Books)
{
	// 输出 book 信息
	cout << "Books.book_id:" << Books.book_id << endl;
	cout << "Books.title:" << Books.title << endl;
	cout << "Books.author:" << Books.author << endl;
	cout << "Books.content:" << Books.content << endl;
}

void printbooks_p(struct Books *Books)
{
	// 使用指向该结构的指针访问结构的成员，必须使用 -> 运算符
	// 输出 book 信息
	cout << "Books->book_id:" << Books->book_id << endl;
	cout << "Books->title:" << Books->title << endl;
	cout << "Books->author:" << Books->author << endl;
	cout << "Books->content:" << Books->content << endl;
}