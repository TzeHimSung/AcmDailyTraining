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

int n;
map<string,string>hasSon,hasFa;
string a,b;
set<string>all,notHaveFa;

int main()
{
    all.clear(); notHaveFa.clear();
    hasSon.clear(); hasFa.clear();
    cin>>n;
    while (n--)
    {
        cin>>a>>b;
        hasSon[a]=b; hasFa[b]=a;
        all.insert(a); all.insert(b);
    }
    for (auto i:all)
        if (!hasFa.count(i)) notHaveFa.insert(i);
    cout<<notHaveFa.size()<<endl;
    for (auto i:notHaveFa)
    {
        cout<<i<<" ";
        string tmp=i;
        while (hasSon.count(tmp)) tmp=hasSon[tmp];
        cout<<tmp<<endl;
    }
    return 0;   
}