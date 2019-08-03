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

int t;
const int maxn = 2e3 + 10;

int main() {
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca++) {
        printf("Case #%d: ", ca);
        char s[maxn], t[27];
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        map<char, int>m; m.clear();
        int len = strlen(s + 1), dry = 0, wet = 0, harm = 0;
        for (int i = 1; i <= len; i++)
                if (!m.count(s[i])) m[s[i]] = 1; else m[s[i]]++;
        for (int i = 1; i <= 26; i++) {
            if (t[i] == 'd') dry += m[(char)(i + 'a' - 1)];
            else if (t[i] == 'w') wet += m[(char)(i + 'a' - 1)];
            else if (t[i] == 'h') harm += m[(char)(i + 'a' - 1)];
        }
        if (harm * 4 >= len) puts("Harmful");
        else if (harm * 10 <= len) puts("Recyclable");
        else if (!wet || dry / wet >= 2) puts("Dry");
        else puts("Wet");
    }
    return 0;
}