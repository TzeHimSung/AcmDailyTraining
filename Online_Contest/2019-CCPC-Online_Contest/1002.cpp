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

const int maxn = 1e5 + 10, add = 1e7;
struct Node {
    int minn, pos;
} segt[maxn << 2];
int a[maxn],cnt[maxn];

void maintain(int curpos) {
    segt[curpos].minn = min(segt[lson].minn, segt[rson].minn);
    segt[curpos].pos = segt[lson].pos + segt[rson].pos;
}

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].minn = cnt[curl];
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

void update(int curpos, int pos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].minn += add;
        return;
    }
    int mid = curl + curr >> 1;
    if (pos <= mid) update(lson, pos, curl, mid);
    else update(rson, pos, mid + 1, curr);
    maintain(curpos);
}

int queryKth(int curpos, int curl, int curr, int k) {
    if (curl == curr)
        return segt[curpos].pos;
    int mid = curl + curr >> 1;
    if (segt[lson].minn >= k)
        return queryKth(lson, curl, mid, k);
    else
        return queryKth(rson, mid + 1, curr, k - segt[lson].minn);
}

int query(int curpos,int curl,int curr,int ql,int qr){
	if (ql<=curl && curr<=qr){
		return segt[curpos].minn;
	}
	int mid=curl+curr>>1;
	if (ql<=mid) return query(lson,curl,mid,ql,qr);
	else if (mid<qr) return query(rson,mid+1,curr,ql,qr);

}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
		for (int i=0;i<maxn;i++) cnt[i]=0;
        int n, m, lastAns = 0; scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
        build(1, 1, n);
        while (m--) {
            int op; scanf("%d", &op);
            if (op == 1) {
                int pos; scanf("%d", &pos);
                pos ^= lastAns;
                update(1, pos, 1, n);
            } else {
                int ql, qr; scanf("%d%d", &ql, &qr);
                ql ^= lastAns, qr ^= lastAns;
            }
        }
    }
    return 0;
}

