#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

int dl[20][100010], dr[20][100010];
int query(int d[][100010], int l, int r, int maxx) {
    int t = log2(r - l + 1);
    if (maxx)return max(d[t][l], d[t][r - (1 << t) + 1]);
    return min(d[t][l], d[t][r - (1 << t) + 1]);
}
void init(int d[][100010], int a[], int len, int maxx) {
    for (int i = 0; i < len; i++)d[0][i] = a[i];
    int t = 1;
    for (int i = 1; t <= len; i++) {
        for (int j = 0; j + t < len; j++)
            if (maxx)d[i][j] = max(d[i - 1][j], d[i - 1][j + t]);
            else d[i][j] = min(d[i - 1][j], d[i - 1][j + t]);
        t <<= 1;
    }
}

int L[100010], R[100010];
int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d%d", &L[i], &R[i]);
    init(dl, L, n, 1);
    init(dr, R, n, 0);

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int l = ans, r = n - i + 1;
        while (l <= r) {
            int mid = l + r >> 1;
            //cout<<i<<" "<<mid<<" "<<query(dl,i-1,i+mid-2,1)<<" "<<query(dr,i-1,i+mid-2,0)<<"\n";
            if (query(dr, i - 1, i + mid - 2, 0) - query(dl, i - 1, i + mid - 2, 1) + 1 >= mid) {
                ans = max(ans, mid); l = mid + 1;
            } else r = mid - 1;
        }
    }
    printf("%d\n", ans);
}