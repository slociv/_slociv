#include<iostream>
#include<string>

//深拷贝
int main() {
	int a = 1;
	int b = a;
	a = 2;

	std::cout << a << b << std::endl;
}




//C++的浅拷贝(shallow copy)
class String {
private:
	char* m_str;
	unsigned int m_size;
public:
	String(const char* str) {
		m_size = strlen(str);
		m_str = new char[m_size + 1];
		memcpy(m_str, str, m_size + 1);
	};
	friend std::ostream& operator<<(std::ostream& stream, const String& str);

};
//std::ostream&是返回值，(std::ostream& stream,operator<<是函数名称, const String& str) 这个是参数
std::ostream& operator<<(std::ostream& stream, const String& str) {
	std::cout << str.m_str;
	return stream;
}

int main() {
	String str1 = "hello";
	//这里的str2=str1就是浅拷贝,将str1的地址指针m_str赋值给str2
	String str2 = str1;
	std::cout << str1 << str2 << std::endl;
	return 0;
}
