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

string a, b;
int c = 1, d = 1;

int main() {
    cin >> a >> b;
    for (auto i : a) c = c * (i - 'A' + 1);
    for (auto i : b) d = d * (i - 'A' + 1);
    if (c % 47 == d % 47) puts("GO"); else puts("STAY");
    return 0;
}