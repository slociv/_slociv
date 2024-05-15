#include<iostream>
static int global = 10;
int main() {
	if (global >= 0) {
		std::cout << "正数" << std::endl;

	}
	else
	{
		std::cout << "负数" << std::endl;
	}
	//等价
	//三元运算符可以嵌套,但是太难看了,只有代码量折叠的一点点好处
	global>=0? std::cout << "正数" << std::endl: std::cout << "负数" << std::endl;
	return  0;
}