#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        a -= b;
        ll ans = a / 6;
        if (a % 6)
            ans++;
        printf("%lld\n", ans);
    }
}