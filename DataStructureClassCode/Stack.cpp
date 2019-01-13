#include <bits/stdc++.h>

using namespace std;

const int maxn=100;
int stack_1[maxn], pointer=0;
stack<int>stack_2;

int main()
{
    int n; cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x; cin>>x;
        stack_1[++pointer]=x;
        stack_2.push(x);
    }
    while (pointer>0) 
        cout<<stack_1[pointer--]<<" ";
    cout<<endl;
    while (!stack_2.empty())
    {
        cout<<stack_2.top()<<" ";
        stack_2.pop();
    }
    return 0;
}