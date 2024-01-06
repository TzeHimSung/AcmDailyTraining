#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e8 + 10, maxp = 6e6 + 10;
int prime[maxp], cnt = 0;
bool isPrime[maxn];

void getPrime(int n) {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            isPrime[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
}

void solve()
{
    int n; cin>>n;
    getPrime(1e8);
    int curr = 1, cnt = 0;
    while (1) {
        curr++;
        if (isPrime[curr]) {
            if (curr > n) {
                cout << cnt << '\n';
                break;
            } else {
                cout << curr << '\n';
                cnt++;
                n -= curr;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}