#include <bits/stdc++.h>

using namespace std;

struct info {
    long long int price, weight;
};

int main(void) {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        vector <info> water(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &water[i].price, &water[i].weight);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < 32; j++) {
                water.emplace_back((info) {
                    water[i].price * (1 << j), water[i].weight * (1 << j)
                });
                if (water.back().weight > m) {
                    break;
                }
            }
        }
        unordered_map <int, long long int> obj(20001);
        for (auto e : water) {
            if (!obj.count(e.weight) || obj[e.weight] > e.price) {
                obj[e.weight] = e.price;
            }
        }
        long long int ans = 10000000000000000LL;
        int rec = 0;
        vector <long long int> f(20001, 10000000000000000LL);
        f[0] = 0;
        for (auto e : obj) {
            int weight = e.first;
            long long int price = e.second;
            for (int j = m + 10000; j >= 0; j--) {
                if (j >= weight) {
                    f[j] = min(f[j - weight] + price, f[j]);
                }
                if (j >= m) {
                    if (ans > f[j]) {
                        ans = f[j];
                        rec = j;
                    } else if (ans == f[j]) {
                        rec = max(rec, j);
                    }
                }
            }
        }
        printf("%lld %d\n", ans, rec);
    }
    return 0;
}