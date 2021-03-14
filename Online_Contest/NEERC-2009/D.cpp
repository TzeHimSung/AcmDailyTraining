#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
 
const int maxn=1e4+10;
int cnt=0;
map<string,int>id;
map<pair<int,int>,int>check;
int a[maxn][12];
 
int get_id(string &x)
{
    if(id.count(x)) return id[x];
    return (id[x] = cnt++);
}
 
int main()
{
    int n, m;
    loop:
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        getchar();
        cnt = 0;
        int ch;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                string x;
                while((ch=getchar())!=EOF && ch!=',' && ch!='\n') x+=ch;
                int id=get_id(x);
                a[i][j]=id;
            }
        }
        for (int c1=1;c1<m;c1++)
        {
            for (int c2=c1+1;c2<=m;c2++)
            {
                check.clear();
                for (int r=1;r<=n;r++)
                {
                    pair<int, int> x = mp(a[r][c1], a[r][c2]);
                    if(check.count(x))
                    {
                        printf("NO\n");
                        printf("%d %d\n",check[x],r);
                        printf("%d %d\n",c1,c2);
                        goto loop;
                    }
                    else check.insert(mp(x, r));
                }
            }
        }
        printf("YES\n");
    }
    return 0;
}