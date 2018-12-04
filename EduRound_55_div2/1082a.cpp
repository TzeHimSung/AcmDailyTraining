//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
#include <array>
#include <cstdint>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
//define
#define ll long long 
#define pb push_back
#define mp make_pair 
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-8

using namespace std;

int t,n,x,y,d;

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d%d%d",&n,&x,&y,&d);
        int ans=INT_MAX;
        int tmp1=-1,tmp2=-1,tmp3=-1;
        if ((x-y)%d==0) tmp1=abs(x-y)/d;
        if ((y-1)%d==0)
        {
            tmp2=(y-1)/d;
            int k=(x-1)/d;
            if ((x-1)%d!=0) k++;
            tmp2+=k;
        }
        if ((n-y)%d==0)
        {
            tmp3=(n-y)/d;
            int k=(n-x)/d;
            if ((n-x)%d!=0) k++;
            tmp3+=k;
        }

        if (tmp1!=-1) ans=min(ans,tmp1);
        if (tmp2!=-1) ans=min(ans,tmp2);
        if (tmp3!=-1) ans=min(ans,tmp3);
        if (ans!=INT_MAX) printf("%d\n",ans); else puts("-1");
    }
    return 0;
}