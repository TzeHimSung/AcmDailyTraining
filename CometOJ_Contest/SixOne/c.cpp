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

int main() {
    int t; cin >> t; cin.get();
    while (t--) {
        // string s, t; cin >> s >> t;
        string s, t;
        getline(cin, s);
        getline(cin, t);
        int len1 = s.size(), len2 = t.size(), cnt = 0;
        if (len1 - len2 != 2) {
            puts("0"); continue;
        }
        if (len2 == 0 && len1 == 2) {
            puts("1"); continue;
        }
        for (int p1 = 0, p2 = 0; p1 < len1; p1++) {
            if (p2>=len2 || s[p1] != t[p2]) {
                cnt++;
            } else ++p2;
        }
        if (cnt != 2) puts("0"); else puts("1");
    }
    return 0;
}