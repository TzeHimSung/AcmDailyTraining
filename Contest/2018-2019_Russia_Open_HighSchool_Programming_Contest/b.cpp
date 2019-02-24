#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
const int maxn = 2e5 + 10;
char tmp[maxn], ans1[101][maxn];
vector<char> ans2[101];
int id[maxn], cnt = 0, len = 0;
void read1()
{
    len = 0;
    char ch = getchar();
    memset(tmp, 0, sizeof tmp);
    while(!isalpha(ch)) ch = getchar();
    while(isalpha(ch))
    {
        tmp[len++] = ch;
        ch = getchar();
    }
}
void read2()
{
    len = 0;
    char ch = getchar();
    memset(tmp, 0, sizeof tmp);
    while(ch != '\\')
    {
        tmp[len++] = ch;
        ch = getchar();
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    while(1)
    {
        while(getchar() != '\\');
        read1();
        if( strcmp(tmp, "begin") == 0) break;
        read1();
        cnt++;
        strcpy(ans1[cnt], tmp);
    }
    //cout<<1<<endl;
    while(getchar() != '\\');
    //cout<<1<<endl;
    read1();
    //cout<<1<<endl;
    int flag = 0;
    //cout<<cnt<<endl;
    for(int i = 1; i <= cnt; i++)
    {
        read1();
        for(int j = 1; j <= cnt; j++)
            if(strcmp(tmp, ans1[j]) == 0)
            {
                id[j] = i;
                if(j != i)
                    flag = 1;
            }
        read2();
        for(int j = 0; j < len; j++)
            ans2[i].push_back(tmp[j]);
        read1();
    }
    if(flag)
    {
        puts("Incorrect");
        puts("\\begin{thebibliography}{99}");
        for(int i = 1; i <= cnt; i++)
        {
            printf("\\bibitem{%s}", ans1[i]);
            for(int j = 0; j < ans2[id[i]].size(); j++)
                printf("%c", ans2[id[i]][j]);
        }
        puts("\\end{thebibliography}");
    }
    else  puts("Correct");
}