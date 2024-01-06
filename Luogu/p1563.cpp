#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Student {
    int direction;
    string job;

    Student() {
        this->direction = 0;
        this->job = "";
    }

    Student(int _direction, string _job) {
        this->direction = _direction;
        this->job = _job;
    }
};

struct Ring {
    int tot, cur_pos, cur_direction;
    const vector<Student>* student;
    string cur_job;
    int step_dict[2][2]{ -1,1,1,-1 };

    Ring() {
        this->tot = this->cur_pos = this->cur_direction = 0;
        this->student = nullptr;
        this->cur_job = "";
    }

    Ring(const vector<Student>& _student) {
        this->cur_pos = 0;
        this->tot = _student.size();
        this->student = &_student;
        this->cur_job = (*this->student)[0].job;
        this->cur_direction = (*this->student)[0].direction;
    }

    void move(int direction, int cnt) {
        // cur_direction 0:in 1:out
        // direction 0:left 1:right
        int step = this->step_dict[this->cur_direction][direction];
        this->cur_pos += cnt * step;
        if (this->cur_pos < 0) this->cur_pos += tot;
        else if (this->cur_pos >= tot) this->cur_pos -= tot;
        this->cur_job = (*this->student)[this->cur_pos].job;
        this->cur_direction = (*this->student)[this->cur_pos].direction;
    }
};

void solve() {
    int n, m;cin >> n >> m;
    vector<Student> student;
    for (int i = 0;i < n;i++) {
        int pos; string job; cin >> pos >> job;
        student.push_back(Student(pos, job));
    }
    Ring ring = Ring(student);
    while (m--) {
        int pos, cnt;
        cin >> pos >> cnt;
        ring.move(pos, cnt);
    }
    cout << ring.cur_job << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}