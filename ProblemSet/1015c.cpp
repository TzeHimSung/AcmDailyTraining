//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
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

const int maxn=1e5+10;
int n,m;
struct Node
{
    int a,b,c;
    Node(){}
    Node(int a,int b,int c):a(a),b(b),c(c){}

    bool operator<(const Node &rhs)const
    {
        if (c!=rhs.c) return c>rhs.c;
        else return a>rhs.a;
    }
};

Node song[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    ll sum=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&song[i].a,&song[i].b);
        song[i].c=song[i].a-song[i].b;
        sum+=song[i].a;
    }
    sort(song+1,song+1+n);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (sum<=m) break;
        ans++;
        sum-=song[i].a-song[i].b;
    }
    if (sum<=m) printf("%d\n",ans); else puts("-1");
    return 0;
}