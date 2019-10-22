#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>

#define ll long long
#define pr(x) cout << #x << " = " << (x) << '\n';

using namespace std;
 
struct Block {
    int ur, uc, dr, dc, color;
    bool operator < (const Block &t)const {
        if (ur == t.ur) return uc < t.uc;
        return ur < t.ur;
    }
}b[20];
 
int ans, n;
vector<int> on[20];
 
bool ok(int sta, int x) {
    if (on[x].size() == 0) return 1;
    for (int i = 0; i < on[x].size(); ++i) {
        if (!(sta & (1 << on[x][i]))) return 0;
    }
    return 1;
}
 
void dfs(int use, int sta) {
    if (use >= ans) return;
    if (sta == (1 << n) - 1) {
        ans = use;
        return;
    }
    int org = sta;
    for (int i = 0; i < n; ++i) {
        if ((sta & (1 << i))|| !ok(sta, i)) continue;
        sta |= 1 << i;
        for (int j = 0; j < n; ++j) {
            if (!(sta & (1 << j)) && b[j].color == b[i].color && ok(sta, j))
                sta |= 1 << j;
        }
        dfs(use + 1, sta);
        sta = org;
    }
}
 
int main()
{
    int kase; scanf("%d", &kase);
    while (kase --) {

        scanf("%d", &n);
        ans = n;
        for (int i = 0; i < n; ++i) {
            on[i].clear();
            scanf("%d%d%d%d%d", &b[i].ur, &b[i].uc, &b[i].dr, &b[i].dc, &b[i].color);
        }
        sort(b, b + n);
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (b[j].dr == b[i].ur && ((b[i].uc <= b[j].uc && b[j].uc <= b[i].dc) || (b[i].uc <= b[j].dc && b[j].dc <= b[i].dc))) {
                    on[i].push_back(j);
                }
            }
        }
 
        dfs(0, 0);
 
        printf("%d\n", ans);
    }
    return 0;
}
