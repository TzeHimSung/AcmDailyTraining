#include <iostream>
#include <cstdio>
#include <cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int ans;
int a[12], b[12], u[12], t[12], r[12];
int main()
{
    // freopen("input.txt","r",stdin);
    for(int i = 0; i < 10; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    for(int i = 0; i < 10; i++)
    {
        scanf("%d%d%d", &u[i], &r[i], &t[i]);
    }
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 10; j++)
        {
            if(ans < t[j])
            {
                if(t[j] < ans + a[j]) t[j] = ans + a[j];
                ans = ans + a[j] + b[j];
                //if(t[j]<=ans) t[j]=ans;
                continue;
            }
            int k = (ans - t[j]) / (u[j] + r[j]);
            //ans+=k*(u[j]+r[j]);
            t[j] += k * (u[j] + r[j]);
            if(ans < t[j] + u[j])
            {
                //if(t[j]<ans+u[j]+a[j]) t[j]=ans+u[j]+a[j];
                ans = t[j] + u[j] + a[j];
                t[j] = max(ans, t[j] + u[j] + r[j]);
                ans += b[j];
                //if(t[j]<=ans) t[j]=ans;
                continue;
            }
            if(ans >= t[j] + u[j])
            {
                ans += a[j]; //+b[j];
                t[j] = max(ans, t[j] + u[j] + r[j]);
                ans += b[j];
                continue;
            }
        }
    ans -= b[9];
    cout << ans << endl;
}