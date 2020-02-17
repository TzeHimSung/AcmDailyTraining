#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll res = 0;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll INF = (ll)1 << 60;
    ll u = INF;
    ll d = -INF;
    while (u - d > 1) {
        ll m = (u + d) / 2;
        ll c = 0;
        for (ll i = 0; i < N; i++) {
            if (A[i] * A[i] <= m) c--;
            if (A[i] < 0) {
                ll mn = (m / A[i]) - 5;
                while (mn * A[i] > m) mn++;
                ll pos = lower_bound(A.begin(), A.end(), mn) - A.begin();
                c += N - pos;
            } else if (A[i] > 0) {
                ll mx = (m / A[i]) + 5;
                while (mx * A[i] > m) mx--;
                ll pos = upper_bound(A.begin(), A.end(), mx) - A.begin();
                c += pos;
            } else {
                if (m >= 0) {
                    c += N;
                }
            }
        }
        c /= 2;
        if (c >= K) {
            u = m;
        } else {
            d = m;
        }
    }
    cout << u << endl;
}