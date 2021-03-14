#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;
struct Node
{
    int x,y;
    Node(){}
    Node(int a,int b):x(a),y(b){}
};
Node a[maxn];
int n,p;

int main()
{
    random_device rd;
    scanf("%d%d",&n,&p);
    int num=ceil(1.0*n*p/100.0);
    for (int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    if (n<=2)
    {
        puts("possible");
        return 0;
    }
    for (int i=1;i<=2000;i++)
    {
        int p1=rd()%n,p2=rd()%n;
        while (p1==p2) p2=rd()%n;
        int x1=a[p1].x,y1=a[p1].y,x2=a[p2].x,y2=a[p2].y;
        int ans=2;
        for (int j=0;j<n;j++)
        {
            if (j==p1 || j==p2) continue;
            int xx=a[j].x,yy=a[j].y;
            if ((yy-y2)*(x2-x1)==(y2-y1)*(xx-x2)) ans++;
        }
        if (ans>=num)
        {
            puts("possible");
            goto mark;
        }
    }
    puts("impossible");
    mark:
    return 0;
} 