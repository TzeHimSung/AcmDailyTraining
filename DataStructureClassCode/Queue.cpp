#include <bits/stdc++.h>

using namespace std;

const int maxn=100;
int queue_1[maxn],head=0,tail=0;
queue<int>queue_2;

int main()
{
    int n; cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x; cin>>x;
        queue_1[tail++]=x;
        queue_2.push(x);
    }
    while (head<tail)
        cout<<queue_1[head++]<<" ";
    cout<<endl;
    while (!queue_2.empty())
    {
        cout<<queue_2.front()<<" ";
        queue_2.pop();
    }
    return 0;
}