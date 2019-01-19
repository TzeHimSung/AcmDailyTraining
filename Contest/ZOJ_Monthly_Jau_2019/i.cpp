/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define int int32_t
#define ll int64_t
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

struct Node
{
    int val=0;
    map<int,int>num;
};
const int maxn=1e5+10;
int a[maxn],n,m,t;
Node segT[maxn<<3];

void build(int pos, int newVal, int curPos, int curL, int curR)
{
    if (curL==curR)
    {
        segT[curPos].num.clear();
        segT[curPos].num[newVal]=1;
        segT[curPos].val=newVal;
        return;
    }
    int mid=curL+(curR-curL)/2;
    if (pos<=mid) build(pos, newVal, curPos*2, curL, mid);
        else build(pos, newVal, curPos*2+1, mid+1, curR);
    for (auto i:segT[curPos*2].num)
        if (segT[curPos].num.count(i.first)) 
            segT[curPos].num[i.first]++;
        else
            segT[curPos].num[i.first]=1;
    for (auto i:segT[curPos*2+1].num)
        if (segT[curPos].num.count(i.first)) 
            segT[curPos].num[i.first]++;
        else
            segT[curPos].num[i.first]=1;
}

int signalPointFix(int pos, int newVal, int curPos, int curL, int curR)
{
    if (curL==curR)
    {
        int ret=segT[curPos].val;
        segT[curPos].num.clear();
        segT[curPos].num[newVal]=1;
        return ret; 
    }
    int mid=curL+(curR-curL)/2, rmNum;
    if (pos<=mid) rmNum=signalPointFix(pos, newVal, curPos*2, curL, mid);
        else rmNum=signalPointFix(pos, newVal, curPos*2+1, mid+1, curR);
    if (segT[curPos].num[rmNum]==1) 
        segT[curPos].num.erase(rmNum);
    else
        segT[curPos].num[rmNum]--;
    if (segT[curPos].num.count(newVal))
        segT[curPos].num[newVal]++;
    else
        segT[curPos].num[newVal]=1;
}

map<int,int> query(int curPos, int curL, int curR)
{
    if (curL==curR)
        return segT[curPos].num;
    int mid=curL+(curR-curL)/2;
    map<int,int>leftMap, rightMap, ret; leftMap.clear(); rightMap.clear(); ret.clear();
    leftMap=query(curPos*2, curL, mid);
    rightMap=query(curPos*2+1, mid+1, curR);
    for (auto i:leftMap)
        if (rightMap.count(i.first) && (i.second == rightMap[i.first]))
            ret[i.first]=i.second;
    return ret;
}

int main()
{
    freopen("input.txt","r",stdin);
    cin>>t;
    while (t--)
    {
        init(a,0);
        cin>>n>>m;
        rep1(i,1,n)
        {
            cin>>a[i];
            build(i,a[i],1,1,n);
        }
        while (m--)
        {
            int op; cin>>op;
            if (op==1)
            {
                int x,y; cin>>x>>y;
                signalPointFix(x,y,1,1,n);
            }
            else
            {
                map<int,int>ans;
                ans.clear();
                ans=query(1,1,n);
                if (ans.empty()) cout<<-1<<endl;
                    else cout<<ans.size()<<endl;
            }
        }
    }
    fclose(stdin);
    return 0;
}