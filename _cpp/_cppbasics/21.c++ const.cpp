#include<iostream>

int main() {
	
	const int a = 9;
	int* p =(int*) &a;
	*p = 2;

	std::cout << a <<*p<< std::endl;
	return  0;
}