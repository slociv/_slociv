#include <iostream>
#include <string>

//模板类似于java中的泛型

template <class T,int S>
// Vector 类定义了一个数组 Arr，其类型由 T 确定，大小由 S 确定。此外，它还定义了一个成员函数 GetSize()，用于返回数组的大小 S。

class Vector {
public:
	T Arr[S];
	int GetSize() {
		return S;
	}
};
int main() {
	Vector<int, 10> vec;
	std::cout << vec.GetSize() << std::endl;
	return 0;
}