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

int n;

int main() {
    cin >> n;
    while (n--) {
        string a, b; cin >> a >> b;
        int i = 0, j = 0, aLen = a.size(), bLen = b.size();
        while (i < aLen || j < bLen) {
            if (a[i] == b[j]) i++, j++;
            else if (j && b[j] == b[j - 1]) j++;
            else break;
        }
        if (i == aLen && j == bLen) puts("YES");
        else puts("NO");
    }
    return 0;
}