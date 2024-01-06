#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
bitset<MAXN>p;
vector<int>prime;

void getPrime(int n) {
    p.set();
    p[0] = p[1] = 0;
    for (int i = 2;i * i <= n;i++) {
        if (p[i]) {
            prime.push_back(i);
            for (int j = i << 1;j <= n;j += i) p[j] = 0;
        }
    }
}

void solve() {
    int n;cin >> n;
    for (int i = 4;i <= n;i += 2) {
        for (int j = 0;;j++) {
            if (p[i - prime[j]]) {
                cout << i << '=' << prime[j] << '+' << i - prime[j] << '\n';
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    getPrime(MAXN - 10);
    solve();

    return 0;
}