#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn1 = 1e6 + 10;
const int maxn2 = 1e5 + 1;
int n, num, tot = maxn2, ch[maxn1][26], ed, rt[maxn2], sum;
char s[maxn1], t[maxn1];
vector<int> ans[maxn2];
map<int, int> mapa;
map<int, int> mapb;
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s%s", s, t);
        int lens = strlen(s), lent = strlen(t), id = 0;
        for(int j = 0; j < lent; j++)
            id |= (1 << (t[j] - 'a'));
        if(!mapb.count(id))
            mapb[id] = ++sum, rt[sum] = sum;
        ed = 0;
        for(int j = lens - 1; j >= 0; j--)
            if((id & (1 << s[j] - 'a')) == 0)
            {
                ed = j + 1;
                break;
            }
        int now = rt[mapb[id]], tmp = 0;
        while(tmp != ed)
        {
            int x = s[tmp] - 'a';
            if(!ch[now][x])
            {
                tot++;
                ch[now][x] = tot;
            }
            now = ch[now][x];
            tmp++;
        }
        if(!mapa.count(now))
        {
            num++;
            mapa[now] = num;
        }
        ans[mapa[now]].push_back(i);
    }
    printf("%d\n", num);
    for(int i = 1; i <= num; i++)
    {
        int len = ans[i].size();
        printf("%d", len);
        for(int j = 0; j < len; j++)
            printf(" %d", ans[i][j]);
        puts("");
    }
}