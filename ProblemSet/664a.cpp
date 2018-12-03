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
#define init(a,b) fill(begin(a),end(a),b)
#define eps 1e-8
#define i32 int32_t
#define i64 int64_t
//namespace
using namespace std;
//header end

string a,b;

int main()
{
    cin>>a>>b;
    if (a==b) cout<<a<<endl; else cout<<"1"<<endl;
    return 0;
}