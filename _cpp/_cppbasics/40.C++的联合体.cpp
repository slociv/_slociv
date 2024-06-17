
#include "pch.h"

union MyUnion {
	char a;
	int b;
};
int main() {
	MyUnion mu;
	mu.a = 64;
	mu.b = 65;

	std::cout << mu.a << mu.b << std::endl;

	std::cin.get();

	return 0;
}

//输出：A65 了解即可

