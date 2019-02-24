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

int ret,n=0,m=0;

int main()
{
    puts("? 0 0");
    fflush(stdout);
    scanf("%d",&ret);
    for (int i=29;i>=0;i--)
    {
        int a,b;
        printf("? %d %d\n",n|(1<<i),m); //just guess
        fflush(stdout);
        scanf("%d",&a);
        printf("? %d %d\n",n,m|(1<<i)); //guess too
        fflush(stdout);
        scanf("%d",&b);
        if (a!=b)
        {
            if (a==1) continue;
            else n|=(1<<i),m|=(1<<i);
        }
        else
        {
            if (ret==1) n|=(1<<i);
                else m|=(1<<i);
            ret=a;
        }
    }
    printf("! %d %d\n",n,m);
    fflush(stdout);
    return 0;
}