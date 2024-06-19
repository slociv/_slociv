#include <iostream>
//内置库
int main()
{
    //空间名 作用域 类方法 << 打印
    std::cout << "Hello World!\n";
}


//cpp ->ctrl+f7 编译 生成obj -> 

//下面代码可以执行

#include <iostream>
//内置库

void Log(const char* message) {
    std::cout << message;
}
int main()
{
    //空间名 作用域 类方法 << 打印
    Log("hello world");
}

//--------------------------------------没有引入log文件却可以执行,用void Log(const char* message); 欺骗编译器,连接器可以自动链接,将两个obj 链接到一个文件中,通过链接到一个exe
//------------------study-cpp.cpp-------------
void Log(const char* message);

int main()
{
    //空间名 作用域 类方法 << 打印
    Log("hello world");
}

//-----------------log.cpp

#include <iostream>
//内置库

void Log(const char* message) {
    std::cout << message;
}