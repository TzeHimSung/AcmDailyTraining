// /* basic header */
// #include <bits/stdc++.h>
// /* define */
// #define ll long long
// #define dou double
// #define pb emplace_back
// #define mp make_pair
// #define sot(a,b) sort(a+1,a+1+b)
// #define rep1(i,a,b) for(int i=a;i<=b;++i)
// #define rep0(i,a,b) for(int i=a;i<b;++i)
// #define eps 1e-8
// #define int_inf 0x3f3f3f3f
// #define ll_inf 0x7f7f7f7f7f7f7f7f
// #define lson (curpos<<1)
// #define rson (curpos<<1|1)
// /* namespace */
// using namespace std;
// /* header end */

// int t;
// ll n, g, b;

// int main() {
//     scanf("%d", &t);
//     while (t--) {
//         scanf("%lld%lld%lld", &n, &g, &b);
//         ll goodNum = 0, badNum = 0, weekCount, ans = 0;
//         goodNum = n & 1 ? n / 2 + 1 : n / 2; badNum = n - goodNum;
//         weekCount = goodNum / g - 1;
//         goodNum -= weekCount * g, badNum -= weekCount * b;
//         if (goodNum < 0) goodNum = 0;
//         if (badNum < 0) badNum = 0;
//         ans = weekCount * (g + b);
//         while (goodNum) {
//             int delta = min(g, goodNum);
//             ans += delta; goodNum -= delta;
//             if (goodNum <= 0) break;
//             badNum -= b;
//             if (badNum < 0) badNum = 0;
//             ans += b;
//         }
//         ans += badNum;
//         printf("%lld\n", ans);
//     }
//     return 0;
// }

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

int t;

int main() {
    cin >> t;
    while (t--) {
        ll N, n, g, b; cin >> n >> g >> b;
        N = n, n = n + 1 >> 1;
        // N是总天数，n是至少要做n条好路
        ll ans = (n / g) * (g + b) + n % g;
        if (n % g == 0 && n / g) ans -= b;
        cout << max(ans, N) << endl;
    }
    return 0;
}