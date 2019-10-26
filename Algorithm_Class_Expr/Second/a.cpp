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

const int maxn = 4e5 + 10;
char s[maxn];
int len = 0;

bool check(int p) {
    int st = len - p + 1;
    for (int i = 1; i <= p; i++) {
        if (s[i] != s[st + i - 1]) return false;
    }
    return true;
}

int main() {
    while (~scanf("%s", s + 1)) {
        len = strlen(s + 1);
        vector<int>ans;
        ans.clear();
        for (int p = 1; p <= len; p++) {
            if (check(p)) ans.push_back(p);
        }
        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
        puts("");
    }
    return 0;
}