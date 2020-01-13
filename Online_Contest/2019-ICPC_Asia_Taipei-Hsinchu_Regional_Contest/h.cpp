#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll n; scanf("%lld", &n);
        ll x = (1ll * n * (n + 1)) ^ (n + 1);
        printf("%lld\n", x);
    }
}