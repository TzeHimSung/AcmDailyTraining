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

const int maxn = 1e5 + 10;
int n;
string ans;

int kmp(string s) {
    vector<int> tmp(s.size());
    for (int i = 1; i < s.size(); i++) {
        int k = tmp[i - 1];
        while (s[k] != s[i]) {
            if (!k) {
                k = -1; break;
            }
            k = tmp[k - 1];
        }
        tmp[i] = k + 1;
    }
    return tmp.back();
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (!i) {
            cin >> ans;
            continue;
        }
        string s; cin >> s; string t = s + '#';
        int a = min((int)ans.size(), (int)s.size());
        t.insert(t.end(), ans.end() - a, ans.end());
        int x = kmp(t);
        while (x--) ans.pop_back();
        ans.insert(ans.end(), s.begin(), s.end());
    }
    cout << ans << endl;
    return 0;
}