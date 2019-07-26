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

const int maxn = 1e6 + 10;
unordered_map<string, int>mp;
int q, m;
char rs[maxn];

struct _List {
    string s[maxn];
    int pre[maxn], nxt[maxn], v[maxn];
    int sz, csz, head, tail;

    void init() {
        sz = 2, csz = 0, head = 1, tail = 2;
        pre[head] = 0, nxt[head] = 2;
        pre[tail] = 1, nxt[tail] = 0;
    }
    int app(string _s, int _v) {
        csz++;
        if (csz == m + 1) del(nxt[head]);
        s[++sz] = _s, v[sz] = _v;
        nxt[pre[tail]] = sz;
        pre[sz] = pre[tail];
        nxt[sz] = tail;
        pre[tail] = sz;
        return sz;
    }
    void del(int pos) {
        --csz;
        mp.erase(s[pos]);
        pre[nxt[pos]] = pre[pos];
        nxt[pre[pos]] = nxt[pos];
    }
} _list;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &q, &m);
        _list.init();
        mp.clear();
        rep1(i, 1, q) {
            int op, v, pos; scanf("%d%s%d", &op, rs, &v);
            string s(rs);
            if (!op) {
                if (mp.find(s) != mp.end()) {
                    pos = mp[s];
                    v = _list.v[pos];
                    _list.del(pos);
                }
                mp[s] = _list.app(s, v);
                printf("%d\n", v);
            } else {
                int flag = 0;
                if (mp.find(s) != mp.end()) {
                    pos = mp[s];
                    flag = 1;
                    if (v == -1) {
                        pos = _list.pre[pos];
                        if (pos == _list.head) flag = 0;
                    } else if (v == 1) {
                        pos = _list.nxt[pos];
                        if (pos == _list.tail) flag = 0;
                    }
                }
                if (flag) printf("%d\n", _list.v[pos]);
                else puts("Invalid");
            }
        }
    }
    return 0;
}