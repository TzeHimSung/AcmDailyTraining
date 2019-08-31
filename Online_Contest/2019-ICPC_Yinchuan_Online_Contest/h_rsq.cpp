#include<bits/stdc++.h>
#define ll long long

using namespace std;
struct Info {
    ll Hp, Atk;
    ll t;
    double val;
};
const int maxn = 1e6;
bool dcmp(double a, double b) {
    if (abs(a - b) < 1e-5) {
        return true;
    } return false;
}

ll f[maxn];
int main() {
    for (int i = 1; i <= 10000; i++) {
        f[i] = i * (i + 1) / 2;
    }
    int T;
    scanf("%d", &T);
    for (int kass = 1; kass <= T; kass ++) {
        int n;
        scanf("%d", &n);
        vector<Info> vct(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &vct[i].Hp, &vct[i].Atk);
            ll t = lower_bound(f + 1, f + 1 + 10000, vct[i].Hp) - f - 1;
            if ((t * t + 1) / 2 < vct[i].Hp) t++;
            vct[i].t = t;
        }
        sort(vct.begin(), vct.end(), [](Info a, Info b)->bool{
            return a.Atk * b.t > b.Atk *a.t;
        });
        ll Sumt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            Sumt += vct[i].t;
            ans += Sumt * vct[i].Atk;
        }
        printf("Case #%d: %lld\n", kass, ans);
    }
    return 0;
}