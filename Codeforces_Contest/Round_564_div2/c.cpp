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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

int n;
const int maxn = 2e5 + 10;
queue<int>q;
set<int>s;

int check() {
    queue<int>tmp = q;
    int last = -1;
    while (!tmp.empty()) {
        int curr = tmp.front();
        tmp.pop();
        if (curr < last)
        }
    return 1;
}

int main() {
    cin >> n;
    rep1(i, 1, n) {
        int x; cin >> x;
        if (x) s.insert(x);
    }
    rep1(i, 1, n) {
        int x; cin >> x; q.push(x);
    }
    int ans = 0;
    while (check()) {

    }
    cout << ans << endl;
    return 0;
}