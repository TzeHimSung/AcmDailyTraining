/*

explore for cdq separation

*/

/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <climits>
#include <float.h>
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
#define ll long long
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
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

//problem 1
//有n对数，m个询问，每次询问给出x0 y0，求有多少个xi yi满足xi<=x && yi<=y

void sovle1(int l, int r, vector<Struct>vec1)
{
    //在这里将vec1[l, r]按x从小到大排序
    int mid = (l + r) / 2;
    solve1(l, mid);
    solve1(mid + 1, r);//划分成相互独立的子问题
    //将vec1[l, mid]中的更新操作 和 vec1[mid + 1, r]中的询问操作,存到一个vec2中
    solve2(l, r, vec2);//左半边的更新操作和右半边的询问操作之间有联系
}
void solve2(int l, int r, vector<Struct>vec2)
{
//此时在solve2中已经不需要管x了。在vec2中所有的更新操作的x必然小于等于询问操作的x。

    //在这里将vec2[l, r]按y从小到大排序
    int mid = (l + r) / 2;
    sovle2(l, mid);
    solve2(mid + 1, r);//独立子问题
    //将vec2[l, mid]中的更新操作和vec2[mid + 1, r]中得询问操作存到一个vec3中
    solve3(l, r, vec3);//
}
void solve3（int l, int r, vector<Struct>vec3）
{
//此时在solve3中，x和y都是已经排好序的。从前到后遍历该更新更新该询问询问就好。
    int cal = 0;
    for (Struct tmp : vec3)
    {
        if (tmp.type == Update)  ++cal;
        else tmp.query_anser += cal;
    }
}
//这段代码其中有许多可以优化的地方，但是不要在意细节，主要是为了更加方便地理解算法

int main()
{
    /* main body */
    return 0;
}