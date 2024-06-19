#include<iostream>
#include<string>

class human {
public:
	std::string name;
	human(std::string n) :name(n) {};
};
int main() {
	//栈上申请内存
	human h1("hello");
	//堆上申请内存
	human* h2 = new human("world");

	std::cout << h1.name << std::endl;
	std::cout << h2->name << std::endl;
	//回收内存
	delete h2;

	int* arr = new int[10];
	delete[] arr;
	return  0;
}