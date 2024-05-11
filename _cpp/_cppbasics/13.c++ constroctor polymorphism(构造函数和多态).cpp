#include<iostream>

class player {
public:
	int age;
	player() {
		age = 2;
	}
	player(int a, int b) {
		age = a + b;
	}
	void say() {
		std::cout << age << std::endl;
	}
};

int main() {
	player p1;
	p1.say();
	player p2(2,3);
	p2.say();

	return 0;
}