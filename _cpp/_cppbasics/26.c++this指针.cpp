#include<iostream>
#include<string>

class human {
public:
	int x;
	human(int x) {
        //这个this和h1的内容相同都是指向h1对象的指针
		this->x = x;
		std::cout << this << std::endl;
	}
};

int main() {
	human* h1 = new human(2);
	std::cout << h1->x << std::endl;
	std::cout << h1 << std::endl;
	return  0;
}

