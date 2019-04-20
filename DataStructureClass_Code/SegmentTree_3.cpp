//线段树 区间覆盖
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int minNum, maxNum, sumNum;
    int setv;
};

const int maxn=1e4+10;
Node segT[maxn];
int n,numOfQuery;
int _min,_max,_sum;

void maintain(int curPos, int curL, int curR)
{
    int lson=curPos*2, rson=curPos*2+1;
    if (curR>curL)
    {
        segT[curPos].sumNum=segT[lson].sumNum+segT[rson].sumNum;
        segT[curPos].minNum=min(segT[lson].minNum, segT[rson].minNum);
        segT[curPos].maxNum=max(segT[lson].maxNum, segT[rson].maxNum);
    }
    if (segT[curPos].setv>=0)
    {
        segT[curPos].maxNum=segT[curPos].minNum=segT[curPos].setv;
        segT[curPos].sumNum=(curR-curL+1)*segT[curPos].setv;
    }
}

void pushdown(int curPos)
{
    int lson=curPos*2, rson=curPos*2+1;
    if (segT[curPos].setv>=0)
    {
        segT[lson].setv=segT[rson].setv=segT[curPos].setv;
        segT[curPos].setv=-1;
    }
}

void intervalCover(int curPos, int setVal, int curL, int curR, int qL, int qR)
{
    int lson=curPos*2, rson=curPos*2+1;
    if (qL<=curL && curR<=qR)
        segT[curPos].setv=setVal;
    else
    {
        pushdown(curPos);
        int mid=curL+(curR-curL)/2;
        if (qL<=mid) intervalCover(lson, setVal, curL, mid, qL, qR);
            else maintain(lson, curL, mid);
        if (mid<qR) intervalCover(rson, setVal, mid+1, curR, qL, qR);
            else maintain(rson, mid+1, curR);
    }
    maintain(curPos, curL, curR);
}

void query(int curPos, int curL, int curR, int qL, int qR)
{
    int lson=curPos*2, rson=curPos*2+1;
    if (segT[curPos].setv>=0)
    {
        _min=min(_min, segT[curPos].setv);
        _max=max(_max, segT[curPos].setv);
        _sum=segT[curPos].setv*(min(curR,qR)-max(curL,qL)+1);
    }
    else if (qL<=curL && curR<=qR)
    {
        _min=min(_min, segT[curPos].minNum);
        _max=max(_max, segT[curPos].maxNum);
        _sum+=segT[curPos].sumNum;
    }
    else
    {
        int mid=curL+(curR-curL)/2;
        if (qL<=mid) query(lson, curL, mid, qL, qR);
        if (mid<qR) query(rson, mid+1, curR, qL, qR);
    }
}

//建树
void build(int pos, int newVal, int curPos, int l, int r)
{
    if (l==r)
    {
        segT[curPos].minNum=segT[curPos].maxNum=segT[curPos].sumNum=newVal;
        segT[curPos].setv=-1;
        return;
    }
    int mid=(l+r)/2;
    if (pos<=mid) build(pos, newVal, 2*curPos, l, mid);
        else build(pos, newVal, 2*curPos+1, mid+1, r);
    segT[curPos].minNum=min(segT[2*curPos].minNum, segT[2*curPos+1].minNum);
    segT[curPos].maxNum=max(segT[2*curPos].maxNum, segT[2*curPos+1].maxNum);
    segT[curPos].sumNum=segT[2*curPos].sumNum+segT[2*curPos+1].sumNum;
    segT[curPos].setv=-1;
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
            int l,r,v; cin>>l>>r>>v;
            intervalCover(1,v,1,n,l,r);
        }
        else
        {
            _sum=0, _min=INT_MAX, _max=INT_MIN;
            int l,r; cin>>l>>r;
            query(1,1,n,l,r);
            cout<<_sum<<" "<<_min<<" "<<_max<<endl;
        }
    }
    return 0;
}