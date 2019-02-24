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
#define inf 0x3f3f3f3f
//namespace
using namespace std;
//header end

int n,x;

int main()
{
    scanf("%d%d",&n,&x);
    switch(n%6)
        {
            case 0:
                cout<<x<<endl;break;
            case 1:
                switch(x)
                {
                    case 0:cout<<1<<endl;break;
                    case 1:cout<<0<<endl;break;
                    case 2:cout<<2<<endl;break;
                }
                break;
            case 2:
                switch(x)
                {
                    case 0:cout<<1<<endl;break;
                    case 1:cout<<2<<endl;break;
                    case 2:cout<<0<<endl;break;
                }
                break;
            case 3:
                switch(x)
                {
                    case 0:cout<<2<<endl;break;
                    case 1:cout<<1<<endl;break;
                    case 2:cout<<0<<endl;break;
                }
                break;
            case 4:
                switch(x)
                {
                    case 0:cout<<2<<endl;break;
                    case 1:cout<<0<<endl;break;
                    case 2:cout<<1<<endl;break;
                }
                break;
            case 5:
                switch(x)
                {
                    case 0:cout<<0<<endl;break;
                    case 1:cout<<2<<endl;break;
                    case 2:cout<<1<<endl;break;
                }
                break;
        }
    return 0;
}