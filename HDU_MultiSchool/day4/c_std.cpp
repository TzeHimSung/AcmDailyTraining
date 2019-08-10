#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pLL;
typedef pair<LL, int> pLi;
typedef pair<int, LL> pil;;
typedef pair<int, int> pii;
typedef unsigned long long uLL;

#define lson rt<<1
#define rson rt<<1|1
#define lowbit(x) x&(-x)
#define name2str(name) (#name)
#define bug printf("*********\n")
#define debug(x) cout<<#x"=["<<x<<"]" <<endl
#define FIN freopen("D://Code//in.txt","r",stdin)
#define IO ios::sync_with_stdio(false),cin.tie(0)

int t, n, k;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        if (1LL * n * (n + 1) / 2 % k || (n == k && n != 1)) {
            printf("no\n");
            continue;
        }
        printf("yes\n");
        int x = k, y = n / k;
        int mp[x + 5][y + 5];
        if (y & 1) {
            for (int i = 1; i <= x; ++i) mp[i][1] = i;
            mp[k / 2 + 1][2] = 2 * k;
            for (int i = k / 2 + 2; i <= x; ++i) mp[i][2] = i - k / 2 - 1 + k;
            for (int i = 1; i <= k / 2; ++i) mp[i][2] = k + k / 2 + i;
            for (int i = 1; i <= x; ++i) mp[i][3] = 4 * k + k / 2 + 2 - mp[i][1] - mp[i][2];
            int nx = 1, ny = 4;
            for (int i = 3 * k + 1; i <= n; ++i) {
                mp[nx][ny] = i;
                if (ny % 2 == 0) {
                    if (nx == x) {
                        ++ny;
                    } else {
                        ++nx;
                    }
                } else {
                    if (nx == 1) {
                        ++ny;
                    } else {
                        --nx;
                    }
                }
            }
        } else {
            int nx = 1, ny = 1;
            for (int i = 1; i <= n; ++i) {
                mp[nx][ny] = i;
                if (ny % 2 == 1) {
                    if (nx == x) {
                        ++ny;
                    } else {
                        ++nx;
                    }
                } else {
                    if (nx == 1) {
                        ++ny;
                    } else {
                        --nx;
                    }
                }
            }
        }
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                printf("%d%c", mp[i][j], j == y ? '\n' : ' ');
            }
        }
    }
    return 0;
}