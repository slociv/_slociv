#include <iostream>
#include <string>
#include <memory>
//智能指针,自动管理内存,避免内存泄漏
//unique_ptr和shared_ptr的作用
class Human {
public:
	std::string name;
	Human(std::string name) {
		this->name = name;
	}
	~Human() {
		std::cout << "destory human" << std::endl;
	}
};
void test(std::shared_ptr<Human> h) {
	std::cout << h->name << std::endl;
    //指针引用次数
	std::cout << h.use_count() << std::endl;
}
int main() {
	//std::unique_ptr<Human> u1;这个无效
	std::shared_ptr<Human> s;
	{
		//std::unique_ptr<Human> p1(new Human("slociv"));
		//u1 = h1; 这个不对的用shared ptr
		//std::unique_ptr<Human> p1 = std::make_unique<Human>("slociv");
		std::shared_ptr<Human> s1 = std::make_shared<Human>("slociv");
		s = s1;
	}
	test(s);
	return 0;
}



共享指针与智能指针的区别
1.共享指针是一种可以跨作用域使用的智能指针，用于解决智能指针的局限性。
2.共享指针通过开辟额外内存空间来存放引用，支持CPS原理中的内存回收。
3.共享指针的初始化使用make shield函数，参数传递到括号内。


1.智能指针可以与函数参数一起传递，实现函数间的内存管理。
2.智能指针的destroy操作会自动释放内存，无需开发者手动删除。
3.智能指针的use count属性可以用于跟踪对象引用的数量，有助于垃圾回收。