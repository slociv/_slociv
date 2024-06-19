#include<iostream>
class Human {
public:
    int x=0;
    int y=0;
    void Move() {
        x = x + 1;
        y = y + 1;
    }
};


int main()
{
    //空间名 作用域 类方法 << 打印
    Human h1;//类的初始化
    h1.Move();
    Human* hptr=&h1;
    hptr->Move();
    std::cout << h1.x << h1.y << std::endl;
    std::cout << hptr->x << hptr->y << std::endl;
    return 0;
}