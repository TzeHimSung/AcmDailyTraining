#include <bits/stdc++.h>

using namespace std;

const int maxn=200;
char s[maxn];

int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int len = strlen(s);
        int x = 0, y = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '0') y++;
            if(s[i] == '0' && s[(i+1)%len] == '0') x++;
        }
        if(x*len == y*y) cout<<"EQUAL"<<endl;
        else if(x*len > y*y) cout<<"SHOOT"<<endl;
        else if(x*len < y*y) cout<<"ROTATE"<<endl;
    }
    return 0;
}