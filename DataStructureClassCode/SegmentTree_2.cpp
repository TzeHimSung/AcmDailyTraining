//线段树 单点修改 区间修改
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int maxNum, minNum, sumNum;
    int addv;
};

const int maxn=1e4+10;
Node segT[maxn];
int n,numOfQuery;
int _sum, _min, _max;

void maintain(int curPos, int curL, int curR)
{
    int lson=curPos*2, rson=curPos*2+1; 
    segT[curPos].maxNum+=segT[curPos].addv;
    segT[curPos].minNum+=segT[curPos].addv;
    segT[curPos].sumNum+=segT[curPos].addv*(curR-curL+1);
}

void addOperation(int curPos, int addVal, int curL, int curR, int qL, int qR)
{
    int lson=curPos*2, rson=curPos*2+1; //left son && right son
    if (qL<=curL && curR<=qR)
        segT[curPos].addv+=addVal;
    else
    {
        int mid=curL+(curR-curL)/2;
        if (qL<=mid) addOperation(lson, addVal, curL, mid, qL, qR);
        if (mid<qR) addOperation(rson, addVal, mid+1, curR, qL, qR);
    }
    maintain(curPos, curL, curR);
}

void query(int curPos, int addVal, int curL, int curR, int qL, int qR)
{
    int lson=curPos*2, rson=curPos*2+1;
    if (qL<=curL && curR<=qR)
    {
        _sum+=segT[curPos].sumNum+addVal*(curR-curL+1);
        _min=min(_min, segT[curPos].minNum+addVal);
        _max=max(_max, segT[curPos].maxNum+addVal);
    }
    else
    {
        int mid=curL+(curR-curL)/2;
        if (qL<=mid) query(lson, addVal+segT[curPos].addv, curL, mid, qL, qR);
        if (mid<qR) query(rson, addVal+segT[curPos].addv, mid+1, curR, qL, qR);
    }
}

//建树
void build(int pos, int newVal, int curPos, int l, int r)
{
    if (l==r)
    {
        segT[curPos].minNum=segT[curPos].maxNum=segT[curPos].sumNum=newVal;
        return;
    }
    int mid=(l+r)/2;
    if (pos<=mid) build(pos, newVal, 2*curPos, l, mid);
        else build(pos, newVal, 2*curPos+1, mid+1, r);
    segT[curPos].minNum=min(segT[2*curPos].minNum, segT[2*curPos+1].minNum);
    segT[curPos].maxNum=max(segT[2*curPos].maxNum, segT[2*curPos+1].maxNum);
    segT[curPos].sumNum=segT[2*curPos].sumNum+segT[2*curPos+1].sumNum;
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
            addOperation(1,v,1,n,l,r);
        }
        else
        {
            int l,r; cin>>l>>r;
            //query操作需要依赖全局变量
            _sum=0; _min=INT_MAX; _max=INT_MIN;
            query(1,0,1,n,l,r);
            cout<<_sum<<" "<<_min<<" "<<_max<<endl;
        }
    }
    return 0;
}