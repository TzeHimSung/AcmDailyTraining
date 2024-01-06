#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Student {
    int a, b, c, d;

    Student() {
        this->a = this->b = this->c = this->d = 0;
    }

    Student(int _a, int _b) {
        this->a = _a;
        this->b = _b;
        this->c = _a + _b;
        this->d = _a * 7 + _b * 3;
    }

    bool isExcellent() const {
        return this->c > 140 && this->d >= 800;
    }
};

void solve() {
    int n; cin >> n;
    vector<Student>student;
    for (int i = 0;i < n;i++) {
        int num, a, b;cin >> num >> a >> b;
        student.push_back(Student(a, b));
    }
    for (int i = 0;i < n;i++) {
        if (student[i].isExcellent())
            cout << "Excellent\n";
        else
            cout << "Not excellent\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}