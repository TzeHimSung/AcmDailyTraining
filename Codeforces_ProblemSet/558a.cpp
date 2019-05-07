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
#include <iterator>
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
#define init(a,b) fill(begin(a),end(a),b)
#define eps 1e-8
#define pi 3.1415926 
//namespace
using namespace std;
//header end

int n;
const int maxn=1e2+10;
struct Node
{
    int pos,num;
    bool operator<(const Node &rhs)const
    {
        return abs(pos)<abs(rhs.pos);
    }
};

Node a[maxn],b[maxn];
int p=0,q=0;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        if (x>0) a[++p]=Node{x,y};
        else b[++q]=Node{x,y};
    }
    sort(a+1,a+1+p); sort(b+1,b+1+q);
    int m=min(p,q); ll ans=0;
    for (int i=1;i<=m;i++) ans+=a[i].num+b[i].num;
    if (p!=q) ans+=max(a[m+1].num,b[m+1].num);
    printf("%d\n",ans);
    return 0;
}