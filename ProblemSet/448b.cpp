//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
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
#define inf 0x3f3f3f3f
//namespace
using namespace std;
//header end

const int maxn=1e2+10;
char a[maxn],b[maxn];
int f1[26],f2[26],arr=0,aut=0,sign=0,pos=1;

int main()
{
    init(f1,0); init(f2,0);
    scanf("%s",a+1); scanf("%s",b+1);
    int len1=strlen(a+1),len2=strlen(b+1);
    rep1(i,1,len1) f1[a[i]-'a']++;
    rep1(i,1,len2) f2[b[i]-'a']++;
    rep0(i,0,26)
    {
        if (f1[i]<f2[i])
        {
            puts("need tree");
            sign=1;
            break;
        }
        if (f1[i]>f2[i]) aut=1;
    }
    if (sign) return 0;
    rep1(i,1,len2)
    {
        int sign=0;
        rep1(j,pos,len1)
            if (a[j]==b[i])
            {
                pos=j+1;
                sign=1;
                break;
            }
        if (!sign)
        {
            arr=1;
            break;
        }
    }
    if (arr && aut) puts("both");
    else if (arr) puts("array");
    else puts("automaton");
    return 0;
}