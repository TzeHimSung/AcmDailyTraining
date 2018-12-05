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
#define int int32_t
#define ll int64_t
#define dou double
#define pb push_back
#define mp make_pair 
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
//namespace
using namespace std;
//header end

int n=0,m=0,ret1,ret2,nx=0,ny=0;

int main()
{
    printf("? 0 0"); fflush(stdout);
    scanf("%d",&ret1);
    for (int i=29;i>=0;i--)
    {
        int tmp=1<<i;
        nx+=tmp,ny+=tmp;
        printf("? %d %d\n",nx,ny);
        fflush(stdout);
        nx-=tmp,ny-=tmp;
        scanf("%d",&ret2);
        if (ret1*ret2<0)
        {
            if (ret1==1) n+=tmp,nx+=tmp;
                else m+=tmp,ny+=tmp;
            printf("? %d %d\n",nx,ny);
            fflush(stdout);
            scanf("%d",&ret1);
        }
        else
        {
            nx+=tmp;
            printf("? %d %d\n",nx,ny);
            fflush(stdout);
            nx-=tmp;
            scanf("%d",&ret2);
            if (ret2==-1)
            {
                nx+=tmp,ny+=tmp,n+=tmp,m+=tmp;
            }
        }
    }
    printf("! %d %d\n",n,m);
    fflush(stdout);
    return 0;
}