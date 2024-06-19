#include <iostream>

int getInt(int&& a) {
	return a;
}

int main() {
	int num = 5;
	int a = getInt(10);
	//这里的a会报错因为 getInt(int&& a) 只接受左值引用
	int b = getInt(a);

	return 0;
}
