/* Nowcoder Contest 887
 * Problem C
 * Au: SJoshua
 */
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct info {
    int h, c, p;
    bool operator < (const info &e) const {
        return h < e.h;
    }
};

/*
1. 枚举高度
2. 代价 = 这个高度以上的cost之和 + (这个高度以下的数量 - 这个高度的数量) > 0 ? COST(这个高度下的砍树代价) : 0
3. 输出最小的代价

需要：
* 每个高度的数量 ok
* 每个高度的数量的前缀和（从低到高） ok
* 每个高度的代价的前缀和（从高到低） ok
* 对于每个代价：高度的数量的前缀和（从低到高） ok

*/

struct node {
    int id;
    long long int num;
};

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector <info> tree(n + 1);
        vector <long long int> hs(n + 1), numH(n + 1), numP(n + 1), costP(n + 1);
        vector <node> costT[201];
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &tree[i].h, &tree[i].c, &tree[i].p);
            hs[i] = tree[i].h;
        }
        sort(tree.begin(), tree.end());
        sort(hs.begin(), hs.end());
        hs.resize(distance(hs.begin(), unique(hs.begin(), hs.end())));
        unordered_map <int, int> mp;
        for (int i = 0; i < hs.size(); i++) mp[hs[i]] = i;
        for (auto &e : tree) {
            e.h = mp[e.h];
            numH[e.h] += e.p;
            numP[e.h] += e.p;
            costP[e.h] += (long long int) e.c * e.p;
            costT[e.c].push_back({e.h, e.p});
        }
        for (int i = 1; i < n; i++) {
            numP[i] += numP[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            costP[i] += costP[i + 1];
        }
        for (int i = 1; i <= 200; i++) {
            for (int j = 1; j < costT[i].size(); j++) {
                costT[i][j].num += costT[i][j - 1].num;
            }
        }
        long long int ans = LONG_LONG_MAX;
        for (int h = 0; h < n; h++) {
            long long int cur = 0;
            if (h + 1 < n) {
                cur += costP[h + 1];
            }
            if (0 < h) {
                long long int cun = numH[h];
                long long int rem = numP[h - 1];
                if (rem >= cun) {
                    long long int cut = rem - cun + 1;
                    for (int i = 1; i <= 200 && cut > 0; i++) {
                        // costT[i]，比h-1小的最后的数
                        int left = 0, right = costT[i].size() - 1;
                        int tar = h - 1;
                        while (left <= right) {
                            int mid = (left + right) / 2;
                            if (costT[i][mid].id < tar) {
                                left = mid + 1;
                            } else {
                                right = mid - 1;
                            }
                        }
                        long long int pos = min(cut, costT[i][left].num);
                        cut -= pos;
                        cur += pos * i;
                    }
                }
            }
            ans = min(ans, cur);
        }
        printf("%lld\n", ans);
    }
    return 0;
}