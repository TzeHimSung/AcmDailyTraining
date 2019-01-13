//线段树 建立 单点修改 区间查询
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int minNum, maxNum, sumNum;
};

const int maxn=1e4+10;
Node segT[maxn];
int n,numOfQuery;

//signal point fix
void build(int pos, int newVal, int curPos, int l, int r)
{
    if (l==r)
    {
        segT[curPos].minNum=newVal;
        return;
    }
    int mid=(l+r)/2;
    if (pos<=mid) build(pos, newVal, 2*curPos, l, mid);
        else build(pos, newVal, 2*curPos+1, mid+1, r);
    segT[curPos].minNum=min(segT[2*curPos].minNum, segT[2*curPos+1].minNum);
    segT[curPos].maxNum=max(segT[2*curPos].maxNum, segT[2*curPos+1].maxNum);
    segT[curPos].sumNum=segT[2*curPos].sumNum+segT[2*curPos+1].sumNum;
}

int query(int curPos, int curL, int curR, int qL, int qR)
{
    if (qL<=curL && curR<=qR) return segT[curPos].minNum;
    int mid=curL+(curR-curL)/2, ret=INT_MAX;
    if (qL<=mid) ret=min(ret, query(curPos*2, curL, mid, qL, qR));
    if (mid<qR) ret=min(ret, query(curPos*2+1, mid+1, curR, qL, qR));
    return ret;
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x; cin>>x;
        build(i,x,1,1,n);
    }
    cin>>numOfQuery;
    while (numOfQuery--)
    {
        int op; cin>>op;
        if (op==1)
        {
            int i,x; cin>>i>>x;
            build(i,x,1,1,n);
        }
        else
        {
            int l,r; cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
    }
    return 0;
}