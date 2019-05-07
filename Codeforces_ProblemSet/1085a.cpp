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

const int maxn=100;
char s[maxn],s1[maxn];
int len,k=0;

int main()
{
    scanf("%s",s1);
    len=strlen(s1);
    if (len%2==0)
        for (int i=len/2-1;i>=0;i--)
        {
            s[k++]=s1[i];
            s[k++]=s1[len-1-i];
        }
    else
    {
        s[k++]=s1[len/2];
        for (int i=len/2-1;i>=0;i--)
        {
            s[k++]=s1[len-1-i];
            s[k++]=s1[i];
        }
    }
    printf("%s\n",s);
    return 0;
}