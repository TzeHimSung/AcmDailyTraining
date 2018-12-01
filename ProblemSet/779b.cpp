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
#define ll long long 
#define pb push_back
#define mp make_pair 
#define mem(a,b) memset(a,b,sizeof(a))
#define init(a,b) fill(begin(a),end(a),b)
#define eps 1e-8
#define pi 3.1415926 
//namespace
using namespace std;
//header end

string s;
int k,ans=0;

int main()
{
    cin>>s>>k; int re=k;
    int len=s.size();
    for (int i=len-1;i>=0;i--)
    {
        if (s[i]=='0') re--; else ans++;
        if (!re) break;
    }
    if (re) cout<<len-1<<endl; else cout<<ans<<endl;
    return 0;
}