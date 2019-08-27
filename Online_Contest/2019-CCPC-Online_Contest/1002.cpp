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
    int val;
} segt[maxn << 2];
int a[maxn], n;

void maintain(int curpos) {
    segt[curpos].val = segt[lson].val + segt[rson].val;
}

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos] = a[curl];
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

void query(int curpos, int curl, int curr, int k) {
    if (curl == curr)
        return curl;
    int mid = curl + curr >> 1;
    if (segt[lson].val >= k) return query(lson, curl, mid, k);
    else return query(rson, mid + 1, curr, k - segt[lson].val);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {

    }
    return 0;
}

