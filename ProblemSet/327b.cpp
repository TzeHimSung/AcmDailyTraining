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

//O(n)质数筛
//生成2~n的质数存在ans数组里，tot是质数个数，数组下标从1开始
const int maxn=1e7+10; //最多可以判断的质数范围
bool valid[maxn];
int ans[maxn],tot,n;
void getPrime(int n)
{
    tot=0;
    memset(valid,1,sizeof(valid));
    for (int i=2;i<=n;i++)
    {
        if (valid[i]) ans[++tot]=i;
        for (int j=1;(j<=tot) && (i*ans[j]<=n);j++)
        {
            valid[i*ans[j]]=false;
            if (i%ans[j]==0) break;
        }
    }
}

int main()
{
    scanf("%d",&n); 
    getPrime(maxn);
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}