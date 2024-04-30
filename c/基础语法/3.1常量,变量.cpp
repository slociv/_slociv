#include <iostream>
#define dVersion 2009
int  main() {
	std::cout << "hello,你好" << "world,世界" << std::endl;
	int year{ 2024 };
	int mon{ 4 };
	int day{ 30 };

	std::cout << year << mon <<day<< std::endl;
	std::cout << dVersion;
	return 0;
}