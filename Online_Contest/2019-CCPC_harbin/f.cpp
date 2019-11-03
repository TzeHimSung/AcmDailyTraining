/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
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

int solved = 0;
string harbin = "harbin";
map<char, int> cnt[6], aim;

void dfs(int depth) {
    if (depth == 6) {
        solved = 1;
        return;
    } else {
        for (int i = 0; i < 6; ++i) {
            if (cnt[depth][harbin[i]] && !aim[harbin[i]]) {
                aim[harbin[i]]++;
                dfs(depth + 1);
                aim[harbin[i]]--;
                if (solved) return;
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        aim.clear();
        for (int i = 0; i < 6; i++) cnt[i].clear();
        for (int i = 0; i < 6; ++i) {
            string s; cin >> s;
            for (auto j : s) cnt[i][j]++;
        }
        solved = 0;
        dfs(0);
        if (solved) puts("Yes"); else puts("No");
    }
    return 0;
}
