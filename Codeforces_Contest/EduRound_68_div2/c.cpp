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

const int maxn = 110;
int q;

int main() {
    scanf("%d", &q);
    while (q--) {
        string s, t, p; cin >> s >> t >> p;
        int len1 = s.size(), len2 = t.size(), len3 = p.size(), ans = 1;
        int a[26] = {0};
        for (auto c : p) a[c - 'a']++;
        int i = 0, j = 0;
        for (; i < len2; i++) { // i in t
            if (j < len1 && t[i] == s[j]) j++; // j in s
            else if (a[t[i] - 'a']) a[t[i] - 'a']--;
            else {
                ans = 0;
                break;
            }
        }
        if (j != len1) ans = 0;
        if (ans) puts("YES"); else puts("NO");
    }
    return 0;
}