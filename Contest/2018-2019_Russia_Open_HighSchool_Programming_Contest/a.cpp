#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 1e6;
struct Node
{
    int m, n;
};
Node m[223456];
int n;
bool cmp(Node a, Node b)
{
    return a.m < b.m;
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &m[i].n);
        int k = 0, f;
        for(int j = 0; j < m[i].n; j++)
        {
            scanf("%d", &f);
            k = max(k, f);
        }
        m[i].m = k;
    }
    sort(m, m + n, cmp);
    ll ans = 0, nown = m[0].n, nowm = m[0].m;
    for(int i = 1; i < n; i++)
    {
        ans += nown * (m[i].m - nowm);
        nowm = m[i].m;
        nown += m[i].n;
    }
    cout << ans << endl;
}