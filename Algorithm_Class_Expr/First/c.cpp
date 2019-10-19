/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(mat,b) sort(mat+1,mat+1+b)
#define rep1(i,mat,b) for(int i=mat;i<=b;++i)
#define rep0(i,mat,b) for(int i=mat;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e3 + 10;
struct Matrix {
    int x1, x2, y1, y2, w, state[maxn], pos, vis;
};
Matrix mat[maxn];
int n, ans = int_inf;

int check(int rlim) {
    for (int i = 1; i <= mat[rlim].pos; i++)
        if (!mat[mat[rlim].state[i]].vis) return 0;
    return 1;
}

void dfs(int x, int s, int last) {
    if (ans <= x) return;
    if (s == n) {
        ans = min(ans, x);
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!mat[i].vis && (!mat[i].x1 || check(i))) {
            mat[i].vis = 1;
            dfs(x + (last != mat[i].w), s + 1, mat[i].w);
            mat[i].vis = 0;
        }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d%d", &mat[i].x1, &mat[i].y1, &mat[i].x2, &mat[i].y2, &mat[i].w);
    // topological sort
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && mat[i].x1 == mat[j].x2 && !(mat[j].y1 > mat[i].y2 || mat[j].y2 < mat[i].y1))
                mat[i].state[++mat[i].pos] = j;
    dfs(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}