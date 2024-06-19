//需析构函数，解决向上转型的时候无法delete释放的问题

#include <iostream>
#include <string>
	
class Human {
public:
	Human() {
		std::cout << "初始化human" << std::endl;
	};
	//查找他的派生类时候存在析构函数
	virtual ~Human() {
		std::cout << "销毁human" << std::endl;
	}
};


class Student :public Human {
public:
	Student() {
		std::cout << "初始化Student" << std::endl;
	};
	//这里写个override也可以
	~Student() override{
		std::cout << "销毁Student" << std::endl;
	}
};


int main() {
	Human* h1 = new Human();
	delete h1;

	Student* s1 = new Student();
	delete s1;

	Human* h2 = new Student();
	delete h2;
	//这里销毁h2 并没有销毁student 因为已经是human了.虚析构就是为了解决这个上转型销毁问题
	std::cin.get();
	return 0;
}
