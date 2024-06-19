
#include <iostream>
class player {
public:
	static int version;
	static void getv() {
		std::cout << version << std::endl;
	}
};

int player::version = 2;
int main() {
	player p1;
	p1.getv();
    //全局在所有地方都可以访问
	player::getv();
	return 0;
}