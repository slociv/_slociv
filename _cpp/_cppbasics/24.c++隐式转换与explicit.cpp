#include<iostream>
#include<string>

class human {
public:
	std::string name;
	int age;

	//explicit human(std::string n) :name(n) {};会禁止隐式转换
	human(std::string n) :name(n) {};
	human(int a) :age(a) {};
};

void Printable(const human& h) {};
int main() {
	human h1("hello");
	human h2(99);
	//隐式转换
	//这行代码中，右侧的 std::string("world") 会隐式转换为 human 类型，
	//并赋值给变量 h3。
	//这是因为存在一个 human(std::string n) 构造函数，
	//可以将 std::string 类型隐式转换为 human 类型。
	//简单将就是"world"变成了human 类型的h3变量
	human h3 = std::string("world");
	human h4 = 10;

	Printable(std::string("world"));
	Printable(100);
	return  0;
}