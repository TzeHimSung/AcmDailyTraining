#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <sstream>
using namespace std;
stack<int> s;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--)
    {
        string tmp;
        cin >> tmp;
        if(tmp[0] == 'u')
        {
            int val;
            scanf("%d", &val);
            while(val--)
            {
                if(s.empty()) break;
                s.pop();
            }
            continue;
        }
        stringstream ss;
        ss << tmp;
        int val;
        ss >> val;
        s.push(val);
    }
    int ans = 0;
    while(!s.empty())
    {
        int tmp;
        tmp = s.top();
        s.pop();
        ans += tmp;
    }
    ans %= n;
    printf("%d\n", (ans + n) % n);
}