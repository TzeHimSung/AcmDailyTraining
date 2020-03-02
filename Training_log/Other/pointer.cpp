#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int>a;
    for (int i = 1; i <= 8; i++) {
        a.push_back(i);
    }
    auto it = a.begin();
    for (; it != a.end(); it++)
        if (*it == 5) break;
    cout << &it << endl;
    a.insert(a.begin(), 0);
    cout << *it << endl;
    cout << &it << endl;
}