#include <iostream>

class MyClass {
public:
    MyClass() { std::cout << "Constructor called\n"; }
    MyClass(const MyClass&) { std::cout << "Copy constructor called\n"; }
};

MyClass createObject() {
    MyClass temp; // Create a temporary object
    return temp;  // Return the temporary object
}

int main() {
    MyClass obj = createObject(); // Object creation without copy elision
    return 0;
}