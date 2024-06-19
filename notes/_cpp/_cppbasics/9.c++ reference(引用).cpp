
//----------特别繁琐
#include <iostream>
void add(int* a) {
	*a += 1;
}
int main() {
	int num = 9;
	int* p = &num;
	add(p);
	std::cout << num << std::endl;
	return 0;
}

//----------引用
#include <iostream>
void add(int* a) {
	*a += 1;
}
void refadd(int a) {
	a += 1;
}
int main() {
	int num = 9;
	int* p = &num;

	int& p2 = num;
	add(p);
	refadd(p2);
	std::cout << num << std::endl;
	return 0;
}

//----------直接改成引用
#include <iostream>
void add(int* a) {
	*a += 1;
}
void refadd(int& a) {
	a += 1;
}
int main() {
	int num = 9;
	int* p = &num;

	//int& p2 = num;
	add(p);
	refadd(num);
	std::cout << num << std::endl;
	return 0;
}

//引用就是起一个别名
#include <iostream>
void add(int* a) {
	*a += 1;
}
void refadd(int& a) {
	a += 1;
}
int main() {
	int num = 9;
	int* p = &num;

	int& p2 = num;
	add(p);
	refadd(num);
	p2 = 999;
	std::cout << num << std::endl;

	return 0;
}