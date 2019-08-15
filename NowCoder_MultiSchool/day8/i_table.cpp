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

const int mod = 1e9 + 7;
ll solve(ll n, ll m) {
    ll ret = 0;
    for (ll k = 1; k <= n; k++) {
        ll tmp = k * m;
        ret = (ret + (tmp & m)) % mod;
    }
    return ret;
}

int main() {
    // for (ll n = 1; n <= 10; n++)
    //     for (ll m = 1; m <= 10; m++)
    //         printf("n = %lld, m = %lld, ans = %lld\n", n, m, solve(n, m));
    for (ll n = 1; n <= 20; n++) {
        for (ll m = 1; m <= 20; m++) printf("%3lld ", n & 1 ? solve(n, m) : solve(n, m) - solve(n - 1, m));
        puts("");
    }
    return 0;
}
// n==10 m==10
//   1   2   3   4   5   6   7   8   9  10
//   1   2   5   4   5  10  13   8   9  10
//   2   4   6   8  10  12  18  16  18  20
//   2   4   6   8  14  12  22  16  18  28
//   3   6   9  12  15  18  25  24  27  30
//   3   6  11  12  19  22  27  24  27  38
//   4   8  12  16  20  24  28  32  36  40
//   4   8  12  16  20  24  28  32  44  40
//   5  10  15  20  25  30  35  40  45  50
//   5  10  17  20  25  34  41  40  53  50
// n==15 m==15
//   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
//   1   2   5   4   5  10  13   8   9  10  13  20  21  26  29
//   2   4   6   8  10  12  18  16  18  20  14  24  26  36  42
//   2   4   6   8  14  12  22  16  18  28  22  24  30  44  54
//   3   6   9  12  15  18  25  24  27  30  25  36  31  50  65
//   3   6  11  12  19  22  27  24  27  38  27  44  43  54  75
//   4   8  12  16  20  24  28  32  36  40  36  48  52  56  84
//   4   8  12  16  20  24  28  32  44  40  44  48  60  56  92
//   5  10  15  20  25  30  35  40  45  50  47  60  65  70  99
//   5  10  17  20  25  34  41  40  53  50  57  68  65  82 105
//   6  12  18  24  30  36  46  48  54  60  66  72  78  92 110
//   6  12  18  24  34  36  50  48  62  68  66  72  90 100 114
//   7  14  21  28  35  42  53  56  63  70  77  84  99 106 117
//   7  14  23  28  39  46  55  56  71  78  87  92 103 110 119
//   8  16  24  32  40  48  56  64  72  80  88  96 104 112 120