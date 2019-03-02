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

const int maxn=1e3+10;
struct Node
{
    int s,t;
    Node(){}
    Node(int a,int b):s(a),t(b){}
};

Node doc[maxn];
int n;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&doc[i].s,&doc[i].t);
    int ans=0,p=1;
    while (p<=n)
    {
        ans++;
        if ((ans-doc[p].s>=0) && (ans-doc[p].s)%doc[p].t==0) p++;
    }
    printf("%d\n",ans);
    return 0;
}