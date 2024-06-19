#include <iostream>
#include <string>
typedef void(*func)();

//将函数变为参数
void foo() {
	std::cout << "foo" << std::endl;
}

//void Print(void(*func)()) {
//	func();
//}

void Print(func fc) {
	fc();
}
int main() {
	//auto func = foo; 其实用auto就行了没那么多麻烦
	//void(*func)() func = foo;
	func func = foo;
	Print(func);
	return 0;
}
