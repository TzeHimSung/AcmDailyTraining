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

const int maxn = 1e5 + 5;
int a[maxn];
int cnt, root;

struct Node {
    int fa;
    vector<int>deg, chd;
    void init(int _fa, int curr) {
        fa = _fa;
        deg.clear(), chd.clear();
        deg.pb(curr);
    }
} bat[maxn];

void insert(int pos, int curr) {
    if ((int)bat[pos].deg.size() == 3) {
        int fa = bat[pos].fa;
        vector<int>vd, vch;
        vd.swap(bat[pos].deg), vch.swap(bat[pos].chd);
        if (pos == root) {
            root = ++cnt;
            bat[root].init(0, vd[1]);
            bat[++cnt].init(root, vd[0]);
            bat[pos].init(root, vd[2]);
            bat[root].chd.pb(cnt), bat[root].chd.pb(pos);
            if (vch.size()) {
                bat[cnt].chd.pb(vch[0]), bat[vch[0]].fa = cnt;
                bat[cnt].chd.pb(vch[1]), bat[vch[1]].fa = cnt;
                bat[pos].chd.pb(vch[2]), bat[vch[2]].fa = pos;
                bat[pos].chd.pb(vch[3]), bat[vch[3]].fa = pos;
            }
            pos = root;
        } else {
            bat[pos].init(fa, vd[0]);
            bat[++cnt].init(fa, vd[2]);
            bat[fa].deg.pb(vd[1]);
            sort(bat[fa].deg.begin(), bat[fa].deg.end());
            bat[fa].chd.pb(cnt);
            for (int i = bat[fa].chd.size() - 1; i > 1; i--) {
                if (bat[fa].chd[i - 1] != pos) swap(bat[fa].chd[i - 1], bat[fa].chd[i]);
                else break;
            }
            if (vch.size()) {
                bat[pos].chd.pb(vch[0]), bat[vch[0]].fa = pos;
                bat[pos].chd.pb(vch[1]), bat[vch[1]].fa = pos;
                bat[cnt].chd.pb((vch[2])), bat[vch[2]].fa = cnt;
                bat[cnt].chd.pb(vch[3]), bat[vch[3]].fa = cnt;
            }
            pos = fa;
        }
    }
    if (!(int)bat[pos].chd.size()) {
        bat[pos].deg.pb(curr);
        sort(bat[pos].deg.begin(), bat[pos].deg.end());
    } else {
        if (curr < bat[pos].deg[0]) insert(bat[pos].chd[0], curr);
        else if (curr > bat[pos].deg[(int)bat[pos].deg.size() - 1]) insert(bat[pos].chd[(int)bat[pos].chd.size() - 1], curr);
        else {
            for (int i = 1; i < (int)bat[pos].deg.size(); i++)
                if (curr < bat[pos].deg[i]) {
                    insert(bat[pos].chd[i], curr);
                    break;
                }
        }
    }
}

void dfs(int pos) {
    for (int i = 0; i < (int)bat[pos].deg.size(); i++)
        printf("%d%c", bat[pos].deg[i], i == (int)bat[pos].deg.size() - 1 ? '\n' : ' ');
    for (int i = 0; i < (int)bat[pos].chd.size(); i++) dfs(bat[pos].chd[i]);
}

int main() {
    int t; scanf("%d", &t);
    for (int __ = 1; __ <= t; __++) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        cnt = root = 1, bat[root].init(0, a[1]);
        for (int i = 2; i <= n; i++) insert(root, a[i]);
        printf("Case #%d:\n", __);
        dfs(root);
    }
    return 0;
}