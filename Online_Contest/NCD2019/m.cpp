#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

ll mod = 1e9 + 7;
ll qp(ll base, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int b1, p1, b2, p2;
        scanf("%d%d%d%d", &b1, &p1, &b2, &p2);
        double tmp = p1 * log(b1) - p2 * log(b2);
        int l = -1, r = -1;
        if (!b1)
            l = 0;
        else if (!p1)
            l = 1;
        if (!b2)
            r = 0;
        else if (!p2)
            r = 1;
        if (l != -1 && r != -1) {
            if (l == r)
                printf("Lazy\n");
            else if (l < r)
                printf("Congrats\n");
            else
                printf("HaHa\n");
            continue;
        }

        if (fabs(tmp) < 1e-8 && qp(b1, p1) == qp(b2, p2))
            printf("Lazy\n");
        else if (tmp < 1e-8)
            printf("Congrats\n");
        else
            printf("HaHa\n");
    }
}