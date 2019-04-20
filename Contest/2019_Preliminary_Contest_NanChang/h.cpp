#include <string>
#include <iostream>

using namespace std;

const long long int p = 1e9 + 7;

long long int qpow(long long int x, long long int b)
{
    if (b == 0) return 1 % p;
    long long int ret = qpow(x, b >> 1);
    ret = ret * ret % p;
    if (b & 1)
    {
        ret = ret * x % p;
    }
    return ret;
}

int main(void)
{
    long long int n;
    scanf("%lld", &n);
    if (n == 1)
    {
        printf("1\n");
    }
    else if (n == 2)
    {
        printf("4\n");
    }
    else
    {
        printf("%lld\n", 4 * qpow(3, n - 2) % p);
    }
    return 0;
}