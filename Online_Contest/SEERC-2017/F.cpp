#include <bits/stdc++.h>
#define ll long long 
#define pb push_back

using namespace std;

const int maxn=5e3+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct Node
{
    int pos,cost;
    Node(){}
    Node(int a,int b):pos(a),cost(b){}
    
    bool operator<(const Node &rhs)const
    {
        return cost>rhs.cost;
    }
};
int n,cost[maxn];
ll sum=0;
char s1[maxn],s2[maxn];
vector<Node>v1,v2;

bool cmp(const Node &a, const Node &b)
{
    return a.cost>b.cost;
}

bool cmp2(const Node &a, const Node &b)
{
    return a.cost<b.cost;
}

int main()
{
    v1.clear(); v2.clear();
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&cost[i]);
    scanf("%s",s1+1); scanf("%s",s2+1);
    for (int i=1;i<=n;i++)
    {
        if (s1[i]=='1')
        {
            v1.pb(Node(i,cost[i]));
            sum+=cost[i];
        }
        else if (s1[i]=='0' && s2[i]=='1')
            v2.pb(Node(i,cost[i]));
    }
    sort(v1.begin(),v1.end(),cmp);
    int len=v1.size();
    ll begin=sum, ans=inf;
    for (int sz=-1;sz<len;sz++)
    {
        ll tmp=0; sum=begin;
        for (int i=0;i<=sz;i++)
        {
            sum-=v1[i].cost;
            tmp+=sum;
            if (tmp>=ans) break;
        }
        if (tmp>=ans) continue;
        for (int i=sz+1;i<len;i++)
        {
            int p=v1[i].pos;
            if (s2[p]=='0')
            {
                sum-=v1[i].cost;
                tmp+=sum;
                if (tmp>=ans) break;
            }
        }
        if (tmp>=ans) continue;
        vector<Node>v3=v2;
        for (int i=0;i<=sz;i++)
        {
            int p=v1[i].pos;
            if (s1[p]=='1' && s2[p]=='1')
                v3.pb(Node(p,cost[p]));
        }
        sort(v3.begin(),v3.end(),cmp2);
        for (int i=0,lenn=v3.size();i<lenn;i++)
        {
            sum+=v3[i].cost;
            tmp+=sum;
            if (tmp>=ans) break;
        }
        ans=min(ans,tmp);
    }
    printf("%lld\n",ans);
    return 0;
}