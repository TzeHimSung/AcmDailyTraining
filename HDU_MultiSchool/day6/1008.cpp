#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

ll f(ll n, ll m) {
    ll tot = 0;
    for (ll x = n + 1;; x++) {
        if (__gcd(n, x) == 1) {
            tot ++ ;
            if (tot == m) {
                return x;
            }
        }
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        ll k, m;
        cin >> k >> m;
        int flag = 0;
        for (ll n = max(2ll, k - 500ll); n <= k + 500ll; n++) {
            if ((f(n, m)) - n == (n ^ k)) {
                cout << n << endl;
                flag = 1;
                break;
            }
        }
        if (!flag) puts("-1");
    }
    return 0;
}