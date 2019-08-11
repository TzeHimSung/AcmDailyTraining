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
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int mod = 1e9 + 7;

int _hash(string &a, string &b) {
    int lena = a.size(), lenb = b.size(), ret = 0;
    ll hashA = 0, hashB = 0, t = 1;
    for (int i = 1; i <= min(lena, lenb); i++) {
        hashA = hashA + a[lena - i] * t;
        hashB = hashB * mod + b[i - 1];
        if (hashA == hashB) ret = i;
        t *= mod;
    }
    return ret;
}

int main() {
    int n; cin >> n;
    string ans; cin >> ans;
    for (int i = 1; i < n; i++) {
        string cur; cin >> cur;
        int dup = _hash(ans, cur);
        ans += cur.substr(dup, cur.size() - dup);
    }
    cout << ans << endl;
    return 0;
}