#include <bits/stdc++.h>
using namespace std;
char str[100];
long long p[61];
long long mask[61];
void init() {
    p[0] = 1;
    mask[0] = 1;
    for (int i = 1; i < 61; ++i) {
        p[i] = p[i - 1] * 2;
        mask[i] = p[i] | mask[i - 1];
    }
}
long long findMaxBit(long long x) {
    int cnt = 0;
    for (int i = 60; i >= 1; --i) {
        if (x & p[i]) cnt++;
        if (cnt == 2) return ((x >> (i + 1)) << i) | (mask[i - 1] & x);
    }
    return x >> 1;
}
void output(long long x) {
    if (x > 1) output(x >> 1);
    cout << (x & 1);
}
int main() {
    long long k, s = 0;
    cin >> k;
    cin >> str;

    init();
    //cout<<p[60]<<endl<<mask[60]<<endl;
    int len = strlen(str);
    for (int i = len - 1; i >= 0; --i) {
        if (str[i] == '1') s += p[len - i - 1];
    }
    int ans = 0;
    while (s > k) {
        ans++;
        s = findMaxBit(s);
        //output(s);
        //cout<<endl;
    }
    cout << ans;
}