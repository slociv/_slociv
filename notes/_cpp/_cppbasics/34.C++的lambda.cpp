#include <iostream> // 包含标准输入输出流库
#include <string>   // 包含字符串库
#include <functional> // 包含函数库，用于定义函数类型

// 定义一个函数Printable，接受一个函数作为参数
void Printable(const std::function<void(int)> fc) {
	fc(66); // 调用传入的函数，传入参数66
}

int main() {
	int test = 2; // 定义一个整型变量test并初始化为2

	// 定义一个lambda表达式，捕获test变量的引用，接受一个整型参数a
	// auto lambda = [&test](int a) {
	// 	test = 100; // 将test变量的值设置为100
	// 	std::cout << "foo" << a << test << std::endl; // 输出"foo"后跟参数a和test的值
	// };

	// 定义一个lambda表达式，通过值捕获test变量，允许修改捕获的变量，接受一个整型参数a
	auto lambda = [=](int a) mutable {
		test = 100; // 将test变量的值设置为100
		std::cout << "foo" << a << test << std::endl; // 输出"foo"后跟参数a和test的值
	};

	Printable(lambda); // 将lambda表达式作为参数传递给Printable函数

	return 0; // 程序正常退出
}