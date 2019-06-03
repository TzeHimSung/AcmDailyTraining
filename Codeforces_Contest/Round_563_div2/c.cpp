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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

//O(n)质数筛
//生成2~n的质数存在ans数组里，tot是质数个数，数组下标从1开始
const int maxn = 1e5 + 10; //最多可以判断的质数范围
bool valid[maxn];
int prime[maxn], tot = 0, cnt = 0;
void getPrime(int n, int &tot, int *ans) {
    tot = 0;
    memset(valid, 1, sizeof(valid));
    for (int i = 2; i <= n; i++) {
        if (valid[i]) ans[++tot] = i;
        for (int j = 1; (j <= tot) && (i * ans[j] <= n); j++) {
            valid[i * ans[j]] = false;
            if (i % ans[j] == 0) break;
        }
    }
}

int n, ans[maxn];

int check() {
    rep1(i, 2, n)
    if (ans[i] == -1) return 0;
    return 1;
}

int main() {
    cin >> n;
    getPrime(n, tot, prime);
    memset(ans, -1, sizeof(ans));
    while (!check()) {
        int curr = prime[++cnt];
        for (int i = curr; i <= n; i += curr) ans[i] = cnt;
    }
    rep1(i, 2, n) cout << ans[i] << " ";
    puts("");
    return 0;
}