#include <bits/stdc++.h>
using namespace std;
char str[1000];
int main() {
    int len;
    long long a, v, _i, n;
    while (~scanf("%d", &len)) {
        scanf("%s", str);
        a = v = _i = n = 0;
        for (int i = 0; i < len; ++i) {
            if (str[i] == 'a') a++;
            if (str[i] == 'v') v++;
            if (str[i] == 'i') _i++;
            if (str[i] == 'n') n++;
        }
        long long p, q;
        //cout<<a<<' '<<v<<' '<<_i<<" "<<n<<endl;
        p = a * v * _i * n;
        q = len * len * len * len;
        long long t = __gcd(p, q);
        p /= t; q /= t;
        printf("%lld/%lld\n", p, q);
    }

}