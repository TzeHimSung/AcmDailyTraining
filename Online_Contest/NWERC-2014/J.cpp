#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;
int n,ans=0;
map<string,int>m1,m2;
string s;
string a[maxn];
set<string>ss;

int main()
{
    scanf("%d",&n);
    m1.clear(); m2.clear();
    ss.clear();
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        a[i]=s;
        if (!m1.count(s)) m1[s]=1; else m1[s]++;
    }
    for (int i=1;i<=n;i++)
    {
        cin>>s;
        if (!m2.count(s)) m2[s]=1; else m2[s]++;
    }
    for (int i=1;i<=n;i++)
    {
        if (m1.count(a[i]) && m2.count(a[i]) && !ss.count(a[i])) {ans+=min(m1[a[i]],m2[a[i]]); ss.insert(a[i]);}
    }
    printf("%d\n",ans);
    return 0;
}