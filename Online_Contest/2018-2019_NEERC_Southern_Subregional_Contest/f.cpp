#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 1;
int a01[maxn], a10[maxn], a00[maxn];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, n;
    ll ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int tmp1, tmp2;
        scanf("%d%d", &tmp1, &tmp2);
        if(!tmp1)   a00[cnt1++] = tmp2;
        if(tmp1 == 1) a01[cnt2++] = tmp2;
        if(tmp1 == 10) a10[cnt3++] = tmp2;
        if(tmp1 == 11) ans += tmp2;
    }
    int now = n - cnt1 - cnt2 - cnt3;
    int now2 = now + min(cnt2, cnt3);
    int sum = now + 2 * min(cnt2, cnt3);
    sort(a00, a00 + cnt1, cmp);
    sort(a01, a01 + cnt2, cmp);
    sort(a10, a10 + cnt3, cmp);
    for(int i = 0; i < min(cnt2, cnt3); i++)
        ans += (a01[i] + a10[i]);
    if(cnt2 > cnt3)
    {
        int pos1 = cnt3, pos2 = 0;
        while(now2 * 2 > sum && (pos1 < cnt2 || pos2 < cnt1))
        {
            if(a01[pos1] > a00[pos2]) sum++, ans += a01[pos1++];
            else    sum++, ans += a00[pos2++];
        }
    }
    else
    {
        int pos1 = cnt2, pos2 = 0;
        while(now2 * 2 > sum && (pos1 < cnt3 || pos2 < cnt1))
        {
            if(a10[pos1] > a00[pos2]) sum++, ans += a10[pos1++];
            else    sum++, ans += a00[pos2++];
        }
    }
    printf("%d\n", ans);
    return 0;
}