// extern 在 声明函数的时候可以省略,但是在引用外部变量的时候无法省略
//--------------------main.cpp

//必须使用extern
extern int LogLevel;
//可以省略extern
extern int multi(int a, int b);
int main() {

	std::cout << LogLevel<< std::endl;
	std::cout << multi(6,6) << std::endl;
	return 0;
}
//--------------------other.cpp
int LogLevel = 1;

int multi(int a, int b) {
	return 5*5;
}