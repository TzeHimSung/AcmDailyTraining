#include <iostream>

using namespace std;

template<class T>
class Base {
    friend T;
private:
    Base() {
        cout << "class Base is created!" << endl;
    }
    ~Base() {}
};

class B: virtual public Base<B> {
public:
    B() {
        cout << "class B is created!" << endl;
    }
};

class C: public B {
public:
    C() : B() {
        cout << "class C is created!" << endl;
    }
};

int main() {
    B b;
    return 0;
}