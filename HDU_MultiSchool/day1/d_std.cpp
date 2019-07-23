#include<bits/stdc++.h>
using namespace std;

#define mkp make_pair<int,int>
typedef long long ll;
const int maxn = 2e5 + 10;
double eps = 1e-12;
ll n;
struct Node {
    ll l, s, v;
} a[maxn];
int check(double x) {
    double ans = a[n].s - a[n].v * x;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i].s - a[i].v * x <= ans + a[i + 1].l) ans += a[i + 1].l;
        else ans = a[i].s - a[i].v * x;
    }
    return ans <= eps;
}

int main() {
    while (~scanf("%lld", &n)) {
        for (int i = 0; i <= n; i++) scanf("%lld", &a[i].l);
        for (int i = 0; i <= n; i++) scanf("%lld", &a[i].s);
        for (int i = 0; i <= n; i++) scanf("%lld", &a[i].v);
        double l = 0, r = 1e18;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        printf("%.10f\n", r);
    }
    return 0;
}