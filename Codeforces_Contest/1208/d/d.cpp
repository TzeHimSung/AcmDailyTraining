/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

template <class T>
class BIT {
public:
    vector<T> _bit;
    int n;

    BIT(int _n): n(_n) {
        _bit.resize(n);
    }

    void add(int x, T v) {
        while (x < n) {
            _bit[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x) {
        T ret{};
        while (x >= 0) {
            ret += _bit[x];
            x = (x & (x + 1)) - 1;
        }
        return ret;
    }
};

int main() {
    int n; scanf("%d", &n);
    vector<ll> s(n);
    for (int i = 0; i < n; i++) scanf("%lld", &s[i]);
    vector<int> a(n);
    BIT<ll> bit(n);
    for (int i = 0; i < n; i++) bit.add(i, i + 1);
    for (int i = n - 1; i >= 0; i--) {
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + high >> 1;
            if (bit.get(mid) > s[i])
                high = mid;
            else low = mid + 1;
        }
        a[i] = low + 1;
        bit.add(low, -low - 1);
    }
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    puts("");
    return 0;
}

