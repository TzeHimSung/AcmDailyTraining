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

const int maxn=2e3+10;
int n,a[maxn],mod=0;

int main()
{
    init(a,0);
    scanf("%d",&n); printf("%d\n",n+1);
    rep1(i,1,n) scanf("%d",&a[i]);
    for (int i=n;i>=1;i--)
    {
        int k=0; mod%=n;
        while(1)
        {
            if ((mod+a[i])%n==i-1) break;
            k++,mod++;
        }
        printf("1 %d %d\n",i,k);
    }
    printf("2 %d %d\n",n,n);
    return 0;
}