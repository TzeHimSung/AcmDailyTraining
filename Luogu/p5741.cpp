#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Student {
    string name;
    int a, b, c, sum;

    Student() {
        this->a = this->b = this->c = this->sum = 0;
        this->name = "";
    }

    Student(string _name, int _a, int _b, int _c) {
        this->name = _name;
        this->a = _a;
        this->b = _b;
        this->c = _c;
        this->sum = _a + _b + _c;
    }

    bool related(const Student& rhs) {
        return (
            abs(this->a - rhs.a) <= 5 and
            abs(this->b - rhs.b) <= 5 and
            abs(this->c - rhs.c) <= 5 and
            abs(this->sum - rhs.sum) <= 10
            );
    }
};

void solve() {
    int n;cin >> n;
    vector<Student>student;
    for (int i = 0;i < n;i++) {
        string name; int a, b, c;cin >> name >> a >> b >> c;
        student.emplace_back(Student(name, a, b, c));
    }
    for (int i = 0;i < n - 1;i++) {
        for (int j = i + 1;j < n;j++) {
            if (student[i].related(student[j])) {
                cout << student[i].name << ' ' << student[j].name << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}