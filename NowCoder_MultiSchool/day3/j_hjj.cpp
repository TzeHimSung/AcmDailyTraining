#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
unordered_map <string, int> mp;
const int MAXN = 1e6 + 7;
int Q, M;
struct Data {
    string s[MAXN];
    int pre[MAXN], nxt[MAXN], v[MAXN];
    int sz, csz, head, tail;
    void init() {
        sz = 2; csz = 0;
        head = 1; tail = 2;
        pre[head] = 0; nxt[head] = 2;
        pre[tail] = 1; nxt[tail] = 0;
    }
    int app(string _s, int _v) {
        ++csz;
        if (csz == M + 1) {
            del(nxt[head]);
        }
        ++sz;
        s[sz] = _s;
        v[sz] = _v;
        nxt[ pre[tail] ] = sz;
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
} List;
char rs[15];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &Q, &M);
        List.init();
        mp.clear();
        int op, v, pos;
        for (int i = 1; i <= Q; i++) {
            scanf("%d %s %d", &op, rs, &v);
            string s(rs);
            if (op == 0) {
                if (mp.find(s) != mp.end()) {
                    pos = mp[s];
                    v = List.v[pos];
                    List.del(pos);
                }
                mp[s] = List.app(s, v);
                printf("%d\n", v);
            } else {
                bool fg = 0;
                if (mp.find(s) != mp.end()) {
                    pos = mp[s];
                    fg = 1;
                    if (v == -1) {
                        pos = List.pre[pos];
                        if (pos == List.head) fg = 0;
                    } else if (v == 1) {
                        pos = List.nxt[pos];
                        if (pos == List.tail) fg = 0;
                    }
                }
                if (fg) printf("%d\n", List.v[pos]); else puts("Invalid");
            }
        }
    }
    return 0;
}