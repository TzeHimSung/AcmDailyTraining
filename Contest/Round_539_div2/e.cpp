//cf 1113c
#include <bits/stdc++.h>

using namespace std;

const int maxn=3e5+10;
int n,a[maxn],f[maxn],b[1<<20][2];

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	b[0][0]++;
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		ans+=b[f[i]][i&1]++;
	}
	cout<<ans<<endl;
	return 0;
}

