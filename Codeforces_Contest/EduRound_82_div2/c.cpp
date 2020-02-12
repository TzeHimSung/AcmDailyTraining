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

const int maxn = 210;
int t, a[26][26];
char s[maxn];

void init() {
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            a[i][j] = 0;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for (int i = 1; i < len; i++) a[s[i] - 'a'][s[i + 1] - 'a'] = 1;

    }
    return 0;
}