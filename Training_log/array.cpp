#include <iostream>

using namespace std;

class A {
public:
    A() {}
    virtual ~A() {}

    virtual void f() {
        cout << "f() called" << endl;
    }
};

class B: public A {
public:
    B() {}
    ~B() {}

    virtual void f() {
        cout << "f2() called" << endl;
    }
};

int main() {
    cout << sizeof(B) << endl;
}