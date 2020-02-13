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
vector<int>edge[26];
string s, ans;
bool used[26];

void dfs(int v) {
    if (used[v]) return;
    ans += char('a' + v);
    used[v] = 1;
    for (auto to : edge[v]) {
        if (!used[to]) dfs(to);
    }
}

int main() {
    cin >> t;
    while (t--) {
        ans = "";
        for (int i = 0; i < 26; i++) edge[i].clear();
        memset(used, 0, sizeof(used));
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            int a = s[i] - 'a', b = s[i + 1] - 'a';
            edge[a].pb(b), edge[b].pb(a);
        }
        for (int i = 0; i < 26; i++) {
            sort(edge[i].begin(), edge[i].end());
            edge[i].erase(unique(edge[i].begin(), edge[i].end()), edge[i].end());
        }
        for (int i = 0; i < 26; i++)
            if (!used[i] && edge[i].size() <= 1) dfs(i);
        if (ans.size() < 26) {
            puts("NO");
            continue;
        }
        int flag = 1;
        for (int i = 0; i < n - 1; i++) {
            int pos1, pos2;
            for (int j = 0; j < ans.size(); j++) {
                if (ans[j] == s[i]) pos1 = j;
                if (ans[j] == s[i + 1]) pos2 = j;
            }
            if (abs(pos1 - pos2) != 1) flag = 0;
        }
        if (!flag) puts("NO");
        else printf("YES\n%s\n", ans.c_str());
    }
}