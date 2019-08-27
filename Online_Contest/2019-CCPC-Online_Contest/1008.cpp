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
int cook[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d%d", &n, &k);
        priority_queue<int>tail;
        int curr = 1; ll time = k;
        for (int i = 0; i < n; i++) {
            scanf("%d", &cook[i]);
            time += cook[i];
            tail.push(cook[i] % k);
            curr += cook[i] / k;
        }
        while (curr < n) {
            time += k - tail.top();
            tail.pop();
            curr++;
        }
        printf("%lld\n", time);
    }
    return 0;
}

