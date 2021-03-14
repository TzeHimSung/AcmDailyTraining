#include<bits/stdc++.h>
 
#define inf 2147483647
#define MAXN 2020
 
using namespace std;
 
int n,m,ans=inf;
 
int main()
{
	while (cin>>n>>m)
    {
        ans=inf;
        for(int i=1;i<=m;i++)
        {
            int up,down;
		    cin>>up>>down;
		    int x=(down*n)/(up+down)+1;
		    ans=min(ans,up*x-down*(n-x));
	    }
	    printf("%d\n",ans);
    }
	return 0;
}