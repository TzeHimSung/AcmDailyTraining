#include <bits/stdc++.h>
using namespace std;
int id[500001];
vector<int> factors[500001];
bool inSet[500001];
long long cnt[1000001];
void getFactors(int x, vector<int> &factor) {
    int len = sqrt(x);
    for (int i = 2; i <= len; ++i)
        if (x % i == 0) {
            factor.push_back(i);
            if (i * i != x) factor.push_back(x / i);
        }
    factor.push_back(x);
}
void updateCnt(vector<int> &factor, int d) {
    for (auto x : factor) {
        cnt[x] += d;
    }
}
void getPrime(int n, vector<int> &prime) {
    prime.clear();
    int len = sqrt(n);
    for (int i = 2; i <= len; ++i)
        if (n % i == 0) {
            prime.push_back(i);
            while (n % i == 0) n /= i;
        }
    if (n > 1) prime.push_back(n);
}
void dfs(int st, int sel, int product, long long &s, vector<int> &prime, int len) {
    if (sel > 0) {
        if (sel & 1) s += cnt[product];
        else s -= cnt[product];
    }
    for (int i = st; i < len; ++i) {
        dfs(i + 1, sel + 1, product * prime[i], s, prime, len);
    }
}
long long howMany(int x) {
    vector<int> prime;
    getPrime(x, prime);
    int len = prime.size();
    long long rnt = 0;
    dfs(0, 0, 1, rnt, prime, len);
    //cout<<"howMany: "<<rnt<<endl;
    return rnt;
}
int main() {
    int n, T;
    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &id[i]);
        getFactors(id[i], factors[i]);
        //cout<<"factor: ";
        //for (auto x:factors[i]) cout<<x<<' ';
        //cout<<endl;
    }
    long long ans = 0;
    long long sizeOfSet = 0;
    while (T--) {
        int t;
        scanf("%d", &t);
        --t;
        if (inSet[t]) {
            updateCnt(factors[t], -1);
            sizeOfSet--;
            ans -= sizeOfSet - howMany(id[t]);
        } else {
            ans += sizeOfSet - howMany(id[t]);
            updateCnt(factors[t], 1);
            sizeOfSet++;
        }
        inSet[t] = !inSet[t];
        printf("%lld\n", ans);
    }
}