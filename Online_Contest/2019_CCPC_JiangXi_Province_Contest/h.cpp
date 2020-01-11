#include <iostream>
using namespace std;
const long long M = 1000000007;
long long qpow(long long x, long long y) {
    long long ans = 1;
    while (y) {
        if (y & 1) ans = (ans * x) % M;
        x = x * x % M;
        y >>= 1;
    }
    return ans;
}
int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", (n * (n + 1) / 2 % M) * (qpow(n * n, M - 2) % M) % M);

}