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

const int maxn = 1e5 + 10;
struct Node {
    int l, r; //l r是左右子树根节点编号, sum是该节点对应区间内数的个数
    ll sum = 0;
};

Node segt[maxn * 25];
vector<int>v;
int n, m, cnt = 0, root[maxn], a[maxn], ans;

int getid(int x) { //返回数值x在数组v中的位置
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void update(int curl, int curr, int &cur, int last, int pos) { //cur是当前版本树的根节点的编号，last是上一版本树的根节点的编号
    cnt++;
    segt[cnt] = segt[last];
    segt[cnt].sum++;
    cur = cnt;
    if (curl == curr) return;
    int mid = (curl + curr) >> 1;
    if (mid >= pos) update(curl, mid, segt[cur].l, segt[last].l, pos); //往左递归
    else update(mid + 1, curr, segt[cur].r, segt[last].r, pos);
}

int query(int curl, int curr, int rql, int rqr, int k) {
    if (curl == curr) return curl;
    int mid = (curl + curr) >> 1, sum = segt[segt[rqr].l].sum - segt[segt[rql].l].sum;
    if (sum >= k) return query(curl, mid, segt[rql].l, segt[rqr].l, k);
    else return query(mid + 1, curr, segt[rql].r, segt[rqr].r, k - sum);
}

int check(int x) {

}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        rep1(i, 1, n) {
            scanf("%d", &a[i]);
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end()); //v是a数组排序并去重的结果
        rep1(i, 1, n) //n次update,建n棵权值线段树
        update(1, n, root[i], root[i - 1], getid(a[i])); //root[i]代表a[1..i]这个区间弄出来的权值线段树的根节点
        rep1(i, 1, m) {
            // int x, y, k; scanf("%d%d%d", &x, &y, &k);
            // printf("%d\n", v[query(1, n, root[x - 1], root[y], k) - 1]);
            int L, R, p, K; scanf("%d%d%d%d", &L, &R, &p, &K);
            int l = 0, r = 1e6 + 10;
            while (l <= r) {
                int mid = l + r >> 1;
                if (check(mid)) {
                    ans = mid, l = mid + 1;
                } else r = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}