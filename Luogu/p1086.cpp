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

struct HuaSheng {
    int x, y, val;
    HuaSheng() {}
    HuaSheng(int _x, int _y, int _val): x(_x), y(_y), val(_val) {}
    bool operator<(const HuaSheng &rhs)const {
        return val < rhs.val;
    }
};
int n, m, k, curx, cury, ans = 0;
priority_queue<HuaSheng>q;

bool canPick(const HuaSheng &hs, int pickTime) {
    if (k >= pickTime + hs.x) return true;
    else return false;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; scanf("%d", &x);
            if (!x) continue;
            q.push(HuaSheng(i, j, x));
        }
    }
    if (2 * q.top().x + 1 > k) return puts("0"), 0;
    curx = q.top().x, cury = q.top().y, k -= curx + 1;
    ans += q.top().val;
    q.pop();
    while (!q.empty() && canPick(q.top(), abs(q.top().x - curx) + abs(q.top().y - cury) + 1)) {
        k -= abs(q.top().x - curx) + abs(q.top().y - cury) + 1;
        curx = q.top().x, cury = q.top().y, ans += q.top().val;
        q.pop();
    }
    printf("%d\n", ans);
    return 0;
}