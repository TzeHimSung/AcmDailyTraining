#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 200100;
int ch[30][maxn];
int num[30];
char s[maxn];
char ss[maxn];
int A[30];
bool judge()
{
    int now = 0;
    for (int i = 1; i <= 26; i++) A[i] = 1;
    int len = strlen(ss + 1);
    for (int i = 1; i <= len; i++)
    {
        int x = ss[i] - 'a' + 1;
        while (ch[x][A[x]] <= now)
        {
            A[x] ++;
            if (A[x] > num[x]) return false;
        }
        if (ch[x][A[x]] <= now) return false;
        now = ch[x][A[x]];
    }
    return true;
}

int main()
{
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int x = s[i] - 'a' + 1;
        num[x] ++ ;
        ch[x][num[x]] = i;
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", ss + 1);
        if (judge())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}