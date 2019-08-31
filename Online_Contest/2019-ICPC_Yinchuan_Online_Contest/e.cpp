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
} balt[maxn];

void insert(int pos, int curr) {
    if ((int)balt[pos].deg.size() == 3) { // need to split
        int currfa = balt[pos].fa;
        vector<int>vd, vch;
        vd.swap(balt[pos].deg), vch.swap(balt[pos].chd);
        if (pos == root) {
            root = ++cnt;
            balt[root].init(0, vd[1]);
            balt[++cnt].init(root, vd[0]);
            balt[pos].init(root, vd[2]);
            balt[root].chd.pb(cnt), balt[root].chd.pb(pos);
            if ((int)vch.size()) {
                balt[cnt].chd.pb(vch[0]), balt[vch[0]].fa = cnt;
                balt[cnt].chd.pb(vch[1]), balt[vch[1]].fa = cnt;
                balt[pos].chd.pb(vch[2]), balt[vch[2]].fa = pos;
                balt[pos].chd.pb(vch[3]), balt[vch[3]].fa = pos;
            }
            pos = root;
        } else { // no need to split, but have father
            balt[pos].init(currfa, vd[0]);
            balt[++cnt].init(currfa, vd[2]);
            balt[currfa].deg.pb(vd[1]);
            sort(balt[currfa].deg.begin(), balt[currfa].deg.end());
            balt[currfa].chd.pb(cnt);
            for (int i = (int)balt[currfa].chd.size() - 1; i > 1; i--) {
                if (balt[currfa].chd[i - 1] != pos) swap(balt[currfa].chd[i - 1], balt[fa].chd[i]);
                else break;
            }
            if ((int)vch.size()) {
                balt[pos].chd.pb(vch[0]), balt[vch[0]].fa = pos;
                balt[pos].chd.pb(vch[1]), balt[vch[1]].fa = pos;
                balt[cnt].chd.pb((vch[2])), balt[vch[2]].fa = cnt;
                balt[cnt].chd.pb(vch[3]), balt[vch[3]].fa = cnt;
            }
            pos = currfa;
        }
    }
    if (!(int)balt[pos].chd.size()) { // have no child, no need to compare
        balt[pos].deg.pb(curr);
        sort(balt[pos].deg.begin(), balt[pos].deg.end());
    } else { // need to compare
        if (curr < balt[pos].deg[0]) insert(balt[pos].chd[0], curr);
        else if (curr > balt[pos].deg[(int)balt[pos].deg.size() - 1]) insert(balt[pos].chd[(int)balt[pos].chd.size() - 1], curr);
        else {
            for (int i = 1; i < (int)balt[pos].deg.size(); i++)
                if (curr < balt[pos].deg[i]) {
                    insert(balt[pos].chd[i], curr);
                    break;
                }
        }
    }
}

void dfs(int pos) {
    for (int i = 0; i < (int)balt[pos].deg.size(); i++)
        printf("%d%c", balt[pos].deg[i], i == (int)balt[pos].deg.size() - 1 ? '\n' : ' ');
    for (int i = 0; i < (int)balt[pos].chd.size(); i++) dfs(balt[pos].chd[i]);
}

int main() {
    int t; scanf("%d", &t);
    for (int __ = 1; __ <= t; __++) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        cnt = root = 1, balt[root].init(0, a[1]);
        for (int i = 2; i <= n; i++) insert(root, a[i]);
        printf("Case #%d:\n", __);
        dfs(root);
    }
    return 0;
}
