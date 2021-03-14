#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const int maxn=2e3+10;

int n,a,b,z,u,d;
int sign[3];
set<int>pos[3];
string s;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    scanf("%d%d%d",&n,&a,&b);
    cin>>s; int len=s.size();
    for (int i=0;i<len;i++)
    {
        char ch=s[i];
        if (ch=='0')
        {
            z++;
            pos[0].insert(i);
        }
        else if (ch=='1')
        {
            u++;
            pos[1].insert(i);
        }
        else if (ch=='2')
        {
            d++;
            pos[2].insert(i);
        }
    }
    sign[0]=z-a;
    sign[1]=u-b;
    sign[2]=d-(n-(a+b));
    if ((n-(a+b))<0)
    {
        puts("-1");
        return 0;
    }
    int resp=0;
    for (int i=0;i<len;i++)
    {
        int num=s[i]-'0';
        if (sign[num]>0)
        {
            int t; resp++;
            for (int k=0;k<3;k++)
                if (k!=num && sign[k]<0)
                    t=k;
            s[i]='0'+t;
            pos[num].erase(i);
            pos[t].insert(i);
            sign[num]--;
            sign[t]++;
        }
    }
    printf("%d\n",resp);
    cout<<s<<endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}