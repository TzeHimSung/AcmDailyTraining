//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
//define
#define int int32_t
#define ll int64_t
#define dou double
#define pb emplace_back
#define mp make_pair 
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
//namespace
using namespace std;
//header end
 
const int maxn=5e2+10;
ll x[maxn][maxn];

ll fin(ll a[],int n)
{
	ll flag=1;
	ll x=a[1];
	for(int i=1;i<n;i++)
    {
		if(x!=a[i])
            flag=0;
        else 
            flag=x;
	}
	return flag;
}
 
int main()
{
	int n,ii=0,jj=0,q=0;
	ll a[505],b[505];
	ll ai=0,bj=0,count=0;
	init(a,0); init(b,0);
	scanf("%d",&n);
	rep0(i,0,n)
    {
		rep0(j,0,n)
        {
			scanf("%lld",&x[i][j]);
			if(x[i][j]==0)
            {
				ii=i;
				jj=j;
				q++;
			}
		}
	}
	rep0(i,0,n)
		rep0(j,0,n)
			a[i]+=x[i][j];
	rep0(i,0,n)
		rep0(j,0,n)
			b[i]+=x[j][i];
	sort(a,a+n);
	sort(b,b+n);
	ll flagi=fin(a,n),flagj=fin(b,n);
	if(q>1)
		printf("-1\n");
	else if(n==1)
		printf("1\n");	
	else if(flagi!=0 && flagj!=0 && flagi==flagj && a[0]==b[0])
    {
		count=flagi-a[0];
		x[ii][jj]=count;
		int z=0;
		while(z<n)
        {
			ai+=x[z][z];
			z++;
		}
		int w=n-1;
		while(w>=0)
        {
			bj+=x[n-1-w][w];
			w--;
		}
		if(ai==bj && ai==flagi)
        {
			if(count>0)
				printf("%lld\n",count);
			else
				printf("-1\n");
		}
        else 
			printf("-1\n");
	}
    else 
		printf("-1\n");
	return 0;
}
