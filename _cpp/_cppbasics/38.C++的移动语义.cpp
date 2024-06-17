#include <iostream>
#include <utility>

class MyClass {
public:
    int* data;
    MyClass(int size) : data(new int[size]) {
        std::cout << "Constructor" << std::endl;
    }
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor" << std::endl;
    }

    // Move constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Move Constructor" << std::endl;
    }

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
            std::cout << "Move Assignment Operator" << std::endl;
        }
        return *this;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = std::move(obj1);  // Move constructor

    MyClass obj3(20);
    obj3 = std::move(obj2);  // Move assignment operator

    return 0;
}
