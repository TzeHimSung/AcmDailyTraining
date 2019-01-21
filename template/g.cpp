#include<bits/stdc++.h>
using namespace std;
int a[8];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int k, day = 0, week;
        scanf("%d", &k);
        for(int i = 1; i <= 7; i++)
        {
            scanf("%d", &a[i]);
            day += a[i];
        }
        int ans = 1000;
        for(int i = 1; i <= 7; i++)
        {
            week = k % day + day;
            int tot = 0;
            int j = i;
            for(tot = 1;; tot++)
            {
                if(a[j] == 1)
                    week--;
                j = j % 7 + 1;
                if(week == 0)
                    break;
            }
            ans = min(tot, ans);
        }
        printf("%d\n", ans + (k / day - 1) * 7);
    }
}
