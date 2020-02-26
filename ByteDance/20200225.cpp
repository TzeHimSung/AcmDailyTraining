/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

struct Requirement {
    int work, ddl;
    Requirement() {}
    Requirement(int _work, int _ddl): work(_work), ddl(_ddl) {}
    bool operator<(const Requirement &rhs)const {
        return ddl - work > rhs.ddl - rhs.work;
    }
};
vector<Requirement>req;

void getData() {
    string s; getline(cin, s);
    int tmp = 0;
    for (auto i : s) {
        if ('0' <= i && i <= '9') tmp = tmp * 10 + i - '0';
        else {
            req.push_back(Requirement(tmp, 0));
            tmp = 0;
        }
    }
    req.push_back(Requirement(tmp, 0));
    int n = 0; tmp = 0;
    getline(cin, s);
    for (auto i : s) {
        if ('0' <= i && i <= '9') tmp = tmp * 10 + i - '0';
        else req[n++].ddl = tmp, tmp = 0;
    }
    req[n++].ddl = tmp, tmp = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // init
    getData();
    sort(req.begin(), req.end());
    int remainTime = INT_MAX, ans = 0;
    for (auto i : req) {
        if (i.ddl <= remainTime) {
            ans++, remainTime = i.ddl - i.work;
        }
    }
    printf("%d\n", ans);
    return 0;
}

/*
2 2 3 2 4
12 10 9 7 8
3
4 3 1 6 3
9 13 5 12 8
3
 */