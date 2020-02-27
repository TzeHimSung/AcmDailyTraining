/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 15;
int n, sum, a[maxn], yhTri[maxn][maxn];

bool cmp(int p, int q) {
    return p > q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> sum;
    // 当有n个数时，系数为杨辉三角第n行，所以要先构造一个杨辉三角
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 1; i <= n; i++) yhTri[i][1] = yhTri[i][i] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= (i - 1) / 2; j++) {
            yhTri[i][j + 1] = yhTri[i][i - j] = yhTri[i - 1][j]
                                                + yhTri[i - 1][j + 1];
        }
    }
    do {
        int noSolution = 0, curSum = 0;
        for (int i = 1; i <= n; i++) {
            curSum += a[i] * yhTri[n][i];
            if (curSum > sum) {
                // 把后面的数从大到小排，这样下次next_permutation就可以跳过了
                sort(a + i, a + 1 + n, cmp);
                noSolution = 1;
                break;
            }
        }
        if (noSolution) continue;
        // 判断有解
        if (curSum == sum) {
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            puts("");
            break;
        }
    } while (next_permutation(a + 1, a + 1 + n));
    return 0;
}