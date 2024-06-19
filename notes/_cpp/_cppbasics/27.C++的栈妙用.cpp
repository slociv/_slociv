// 1.栈由C++程序自己分配和释放，其作用域相对较小。
// 2.堆内存由程序分配和释放，作用域较大，可能导致内存溢出。
// 3.栈内存分配和释放适用于小型程序，堆内存分配和释放适用于大型程序。


#include<iostream>
#include<string>

class Human {
public:
	std::string name;
	Human(std::string name) {
		this->name = name;
	}
	~Human() {
		std::cout << "destroy name" << std::endl;
	}
};

class printHuman {
private:
	Human* human;
public:
	printHuman(Human* human) {
		this->human = human;
	}
	~printHuman() {
		delete human;
	}
};


int main() {
	//栈上分配
	//Human h1 = std::string("hello");
	//堆上分配
	{
		printHuman ph = new Human("hello");
		//Human* h2 = new Human(std::string("hello"));
	}
	
	return  0;
}

// 在C++中，new操作符用于在堆上分配内存。当你使用new关键字创建一个对象时，这个对象是在堆上分配的，而不是在栈上。new操作符会请求足够的内存来存储对象，并调用对象的构造函数来初始化它。

// 在你提供的代码行中：

// printHuman ph = new Human("hello");
// 这里发生了两件事情：

// new Human("hello") 在堆上创建了一个Human对象，并返回了指向这个新对象的指针。
// 这个指针被用来初始化局部变量ph，ph是一个printHuman类型的栈上分配的变量。
// 所以，new Human("hello") 这部分是在堆上分配的，而printHuman ph 这部分是在栈上分配的，它存储的是指向堆上分配的Human对象的指针。

// 关于隐式转换，C++中确实存在从string到const char* 的隐式转换，但这与栈上分配和堆上分配没有直接关系。当你创建一个std::string对象时，这个对象是在栈上分配的（如果它是局部变量），而const char* 是std::string类的一个成员，它指向std::string对象内部的字符数组。这个字符数组是std::string对象的一部分，因此也是在栈上分配的。

// 例如：

// std::string str = "hello";
// const char* cstr = str.c_str(); // cstr是指向栈上分配的字符数组的指针
// 在这个例子中，str 是一个栈上分配的std::string对象，而cstr 是一个指向str内部字符数组的指针，这个字符数组也是栈上分配的。

// 总结一下：

// 使用new创建的对象是在堆上分配的。
// 局部变量（除非是指针或引用）是在栈上分配的。
// 隐式转换不改变对象的内存分配方式，它只是提供了一种访问或表示对象的不同方式。

// 1.利用栈机制实现内存管理，如使用栈中嵌套指针自动申请和释放内存。
// 2.通过在栈中实例化对象，实现自动申请和释放，提高内存管理效率。
// 3.利用栈和指针的组合，实现对象生命周期管理，确保对象在合适的时间被正确释放。
