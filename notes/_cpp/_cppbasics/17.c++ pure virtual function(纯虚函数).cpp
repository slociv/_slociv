#include <iostream>
class id {
public:
//这里就是纯虚函数和虚函数的区别,相当于一个接口
	virtual void smd() = 0;

};

void Print(id* i) {
	i->smd();
};
class human:public id{
public:
	int age;
	virtual void say() {
		std::cout << "human" << std::endl;
	};
	void smd() {
		std::cout << "smd" << std::endl;
	}
};

class xm :public human {
public:
	void say() override{
		std::cout << "xm" << std::endl;
	}

	void smd() {
		std::cout << "xm" << std::endl;
	}
};


int main() {
	human* h = new human();
	//h->say();
	xm* x= new xm();
	//x->say();
	Print(h);
	Print(x);
	

	return 0;
}