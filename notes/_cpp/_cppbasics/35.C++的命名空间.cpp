#include <iostream>
#include <string>
using namespace std;
//命名空间和套娃
namespace A {
	void print() {
		cout << "a" << endl;
	}
	namespace C {
		void print() {
			cout << "c" << endl;
		}
	}
}
namespace B {
	void print() {
		cout << "b" << endl;
	}
}
int main() {
	A::print();
	B::print();
	A::C::print();
	return 0;
}
