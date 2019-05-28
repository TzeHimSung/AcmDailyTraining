/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

struct Node {
    string s;
    int score, pos;
    Node() {}
    Node(string a, int b, int c) {
        s = a; score = b; pos = c;
    }
    bool operator<(const Node &rhs)const {
        if (s != rhs.s) return s < rhs.s;
        else return score > rhs.score;
    }
};

vector<Node>v;

int main() {
    int n; cin >> n;
    rep1(i, 1, n) {
        string s; int p; cin >> s >> p;
        v.pb(s, p, i);
    }
    sort(v.begin(), v.end());
    for (auto i : v) cout << i.pos << endl;
    return 0;
}