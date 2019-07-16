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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int a[maxn], b[maxn], c[maxn], tmp[maxn], s[maxn];
int sLen = maxn, n;

void calc(int p) {
    if (!a[p + 1]) return; // leader zero in array c
    int bLen = p, cLen = n - p;
    for (int i = 0; i < maxn; i++) b[i] = 0;
    for (int i = 0; i < maxn; i++) c[i] = 0;
    for (int i = 0; i < maxn; i++) tmp[i] = 0;
    rep1(i, 1, bLen) b[bLen - i + 1] = a[i];
    rep1(i, 1, cLen) c[cLen - i + 1] = a[p + i];
    int tmpLen = max(bLen, cLen);
    rep1(i, 1, tmpLen) {
        tmp[i] += b[i] + c[i];
        if (tmp[i] > 9) {
            tmp[i] -= 10;
            tmp[i + 1]++;
        }
    }
    if (tmp[tmpLen + 1]) ++tmpLen;
    if (tmpLen < sLen) {
        sLen = tmpLen;
        memcpy(s, tmp, sizeof(s));
    } else if (tmpLen == sLen) {
        int flag = 0;
        for (int i = tmpLen; i; i--)
            if (tmp[i] < s[i]) {
                flag = 1;
                break;
            } else if (tmp[i] > s[i]) break;
        if (flag) memcpy(s, tmp, sizeof(s));
    }
}

int main() {
    scanf("%d", &n);
    rep1(i, 1, n) scanf("%1d", &a[i]);
    for (int i = (n >> 1); i && sLen == maxn; i--) { // solution exists when sLen!=maxn
        calc(i); calc(n - i);
    }
    for (int i = sLen; i; i--) printf("%d", s[i]);
    puts("");
    return 0;
}