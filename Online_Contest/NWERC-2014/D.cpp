#include <bits/stdc++.h>
#define ll long long 
#define pb push_back

using namespace std;

const int maxn=5e5+10;
ll dp[maxn],n;
bool f;
vector<int>v[maxn];
stack<int>s;
struct Node
{
	char c;
	int l,r;
};
Node p[maxn];

void bfs()
{
	while (!s.empty()) s.pop();
	s.push(0);
	ll tem;
    dp[1]=n;
    int num;
	while (!s.empty())
	{
		num=s.top();
		s.pop();
		if (dp[num]!=-1) continue;
		f=false;
		for (int i=0;i<v[num].size();i++)
		{
			if (dp[v[num][i]]==-1)
			{
				if (!f) s.push(num);
				s.push(v[num][i]);
				f=true;
			}
		}
		if (!f)
		{
			dp[num]=0;
			for (int i=0;i<v[num].size();i++)
			{
				if (i&&v[num][i]==v[num][i-1]) continue;
				tem=dp[v[num][i]];
				if (p[v[num][i]].l==num&&p[v[num][i]].r==num) dp[num]+=tem;
				else if (tem%2==0) dp[num]+=tem/2;
				else
				{
					if (p[v[num][i]].c=='L'&&p[v[num][i]].l==num) dp[num]+=tem/2+1; 
					if (p[v[num][i]].c=='R'&&p[v[num][i]].r==num) dp[num]+=tem/2+1;
					if (p[v[num][i]].c=='L'&&p[v[num][i]].r==num) dp[num]+=tem/2;
					if (p[v[num][i]].c=='R'&&p[v[num][i]].l==num) dp[num]+=tem/2;
				}
			}
		}
	}
	return;
}

int main()
{
	int m;
	while (cin>>n>>m)
	{
		for (int i=0;i<=m;i++) v[i].clear();
		memset(dp,-1,sizeof(dp));
		for (int i=1;i<=m;i++)
		{
			scanf(" %c%d%d",&p[i].c,&p[i].l,&p[i].r);
			v[p[i].l].pb(i);
			v[p[i].r].pb(i);
		}
		for (int i=0;i<=m;i++) sort(v[i].begin(),v[i].end());
		bfs();
		for (int i=1;i<=m;i++)
		{
			if (dp[i]%2==0) printf("%c",p[i].c);
			else 
			{
                if (p[i].c=='L') printf("R");
				    else printf("L");
			}
		}
		printf("\n");
		
	}
	return 0;
}