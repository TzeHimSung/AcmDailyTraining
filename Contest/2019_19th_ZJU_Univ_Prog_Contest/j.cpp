#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef long long ll;

ll read()
{
    ll x = 0; char c = getchar(); ll flag = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
        {
            flag = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9')x = x * 10ll + c - '0', c = getchar();
    return x;
}

int main()
{
    ll T;
    while (scanf("%lld", &T) == 1)
    {
        while (T--)
        {
            ll x;
            x = read();
            if (x % 2 == 0)
            {
                printf("4 %lld\n", 4 + x);
            }
            else
            {
                printf("15 %lld\n", 15 + x);
            }
        }
    }

    return 0;
}