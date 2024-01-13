#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Student {
    string name;
    int y = 0, m = 0, d = 0, idx = 0;

    bool operator< (const Student& rhs) const {
        return (y != rhs.y ? y < rhs.y : m != rhs.m ? m < rhs.m : d != rhs.d ? d<rhs.d : idx > rhs.idx);
    }
};

void solve() {
    int n; cin >> n;
    vector<Student> a(n);
    int idx = 0;
    for (auto& i : a) {
        cin >> i.name >> i.y >> i.m >> i.d;
        i.idx = idx++;
    }
    sort(a.begin(), a.end());
    for (auto i : a) cout << i.name << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}