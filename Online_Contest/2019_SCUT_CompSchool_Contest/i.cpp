#include<iostream>
#include<cstdio>

using namespace std;
const int maxn = 2000000;
int A[maxn];
typedef long long ll;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }
    A[n + 1] = A[n] - 1;
    int mx, mn;
    mx = mn = A[1];
    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (A[i] >= A[i - 1] && A[i] > A[i + 1])
        {
            mx = max(mx, A[i]);
            ans += mx - mn;
            mx = mn = A[i + 1];
            continue;
        }
        if (A[i] > A[i - 1])
        {
            mx = max(A[i], mx);
        }
        if (A[i] <= A[i - 1] && A[i] <= A[i + 1])
        {
            mx = mn = A[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}