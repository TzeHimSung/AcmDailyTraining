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

ll n,m,a,b;

int main()
{
    cin>>n>>m>>a>>b;
    if (n%m==0)
        puts("0");
    else
    {
        ll x=n/m,y=(n/m)+1;
        cout<<min((y*m-n)*a,(n-m*x)*b)<<endl;
    }
    return 0;
}