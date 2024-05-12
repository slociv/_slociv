

#include<iostream>

class human {
public:
	int age;
	void say() {
		std::cout << "iam" + age << std::endl;
	}
};

class game {
public:
	void say() {
		std::cout << "game" << std::endl;
	}
};

//只继承human,使用say2可以直接使用,但是不将human 公开是无法调用say()的
class student :public human {
public:
	void say2() {
		std::cout << "student" << std::endl;
		say();
	}
};
int main() {
	
	student s1;
	s1.say();
	s1.say2();
	return 0;
}

//--------------------------------------------------------多重继承了human和game都有say,	s1.say();就会报错因为他不知道是哪个say,所以要改方法名称,或者指定
#include<iostream>

class human {
public:
	int age;
	void say() {
		std::cout << "iam" + age << std::endl;
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
	void say2() {
		std::cout << "student" << std::endl;
		say();
	}
};
int main() {
	
	student s1;

    //这里会报错
	s1.say();
	s1.say2();
	return 0;
}

//修改后
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
	
	student s1;
	s1.human::say();
	s1.game::say();
	return 0;
}