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

const int maxn=1e2;
string w;
set<string>s;

int main()
{
    cin>>w; int len=w.size();
    s.clear();
    for (int i=len-1;i>=0;i--)
    {
        string tmp="";
        rep0(j,i,len) tmp+=w[j];
        rep0(j,0,i) tmp+=w[j];
        s.insert(tmp);
    }
    cout<<s.size()<<endl;
    return 0;
}