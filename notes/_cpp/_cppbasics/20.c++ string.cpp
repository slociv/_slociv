#include<iostream>
#include<string>

int main() {
	//数组操作
	char str[6] = "hello";
	str[0] = '0';
	//指针
	const char* str1 = "hello";
	//string
	std::string str2 = "hello";
	std::cout << str << std::endl;
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cin.get();
	return  0;
}