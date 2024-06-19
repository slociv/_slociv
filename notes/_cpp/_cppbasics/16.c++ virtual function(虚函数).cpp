#include<iostream>

class human {
public:
	int age;
	void say() {
		std::cout << "age" << std::endl;
	}
};

class game {
public:
	void say() {
		std::cout << "game" << std::endl;
	}
};
class student :public human,public game {
public:
	void speak() {
		std::cout << "student" << std::endl;
		human::say();
	}
};
int main() {
	
	student* s1=new student;
//与15.cpp 对比 
	s1->human::say();
	s1->game::say();

	delete s1;
	return 0;
}
//这里的	extsay(s1); 在 human中的say 没有加入virtual中的时候是直接调用的human 输出的是age,我们想要他直接调用student 的say方法,就需要在virtual 放到human的say中,student的override可以省略
#include<iostream>

class human {
public:
	int age;
    //加上virtual 就可以直接调用到sutdent的say方法了
	virtual void say() {
		std::cout << "age" << std::endl;
	}
};

class game {
public:
	void say() {
		std::cout << "game" << std::endl;
	}
};
class student :public human,public game {
public:
//override 可以省略
	void say() override{
		std::cout << "student" << std::endl;
		human::say();
	}
};

void extsay(human* h) {
	h->say();
}
int main() {
	
	student* s1=new student;
	human* h1 = new human();
//	s1->human::say();
//	s1->game::say();

	
	extsay(s1);
    
	delete s1;
    delete h1;
	return 0;
}