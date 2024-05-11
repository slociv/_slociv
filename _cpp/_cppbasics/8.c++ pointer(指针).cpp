#include <iostream>

int main() {
	int num = 9;
	int* numptr = nullptr;
	int** numptr2 = nullptr;
	numptr = &num;
	numptr2 = &numptr;
	std::cout << numptr << "\t" << *numptr << std::endl;
	std::cout << numptr2 << "\t" << **numptr2 << std::endl;
	return 0;
}