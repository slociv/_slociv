#include <iostream>
#include <string>
//C++的浅拷贝(shallow copy)

//C++中拷贝分为深拷贝和浅拷贝，
//深拷贝复制内容，浅拷贝复制指针。
//讲解了拷贝在string类中的应用，
//并演示了深拷贝和浅拷贝的区别。
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

	~String() {
		delete[] m_str;
	}
	
//	String(const String& other) :m_str(other.m_str), m_size(other.m_size) {

//	};
	String(const String& other) : m_size(other.m_size) {
		m_str = new char[m_size + 1];
		memcpy(m_str, other.m_str, m_size + 1);
	}
	char& operator[](unsigned int index) {
		return m_str[index];
	}
	//友元 ,通过重载输出运算符和使用friend关键字，实现了对私有成员变量的访问和输出。
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
