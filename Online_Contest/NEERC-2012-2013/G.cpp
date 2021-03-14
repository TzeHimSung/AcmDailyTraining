#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long 
#define pb push_back

using namespace std;

int n,m;
map<string,int>M;
map<vector<int>,int>mapSet;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int cntString=0,cntSet=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int total; scanf("%d",&total);
        vector<int>vec;
        for (int j=0;j<total;j++)
        {
            string s; cin>>s;
            if (!M[s]) M[s]=++cntString;
            vec.pb(M[s]);
        }
        sort(vec.begin(),vec.end());
        for (int mask=1;mask<(1<<total);mask++)
        {
            vector<int>v;
            for (int j=0;j<total;j++)
                if ((1<<j) & mask)
                    v.pb(vec[j]);
            mapSet[v]++;
        }
    }
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        int total; scanf("%d",&total);
        bool ok=true;
        vector<int>v;
        for (int j=0;j<total;j++)
        {
            string s; cin>>s;
            if (!M[s]) ok=false;
            v.pb(M[s]);
        }
        sort(v.begin(),v.end());
        if (!ok) puts("0");
            else printf("%d\n",mapSet[v]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}