#include <iostream>

using namespace std;

class Base {
private:
    Base() {
        cout << "class Base is created!" << endl;
    }
    virtual ~Base() {}
};

class A: public Base {
    A() {}
    virtual ~A() {}
};

int main() {
    A a;
    return 0;
}