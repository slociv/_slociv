#include<iostream>
#include<array>
void initArr(int size) {
    //普通数组无法设置
	int* Arr = new int[size];
	for (int i = 0; i < size; i++) {
		Arr[i] = i;
	}
	for (int i = 0; i <size; i++) {
		std::cout << Arr[i] << std::endl;
	}
}

int main() {
	initArr(20);
	return 0;
}