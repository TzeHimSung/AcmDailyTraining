#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int n,t1,t2;
ll total=0,t=0;

pair<ll,ll> solve()
{
	while (1)
	{
		t++;
		if (t%t1==0) total++;
		if (t%t2==0) total++;
		if (total>=n) break;
	}
	if (t%t1!=0)
	{
		total++;
		while (t%t1!=0) t++;
	}
	else if (t%t2!=0)
	{
		total++;
		while (t%t2!=0) t++;
	}
	return make_pair(total,t);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d%d",&n,&t1,&t2);
	pair<ll,ll> p=solve();
	printf("%lld %lld\n",p.first,p.second);

	fclose(stdin);
	fclose(stdout);
	return 0;
}