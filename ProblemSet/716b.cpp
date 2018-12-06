//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
#include <array>
#include <cstdint>
#include <iterator>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
//define
#define int int32_t
#define ll int64_t
#define dou double
#define pb push_back
#define mp make_pair 
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define inf 0x3f3f3f3f
//namespace
using namespace std;
//header end

// const int maxn=5e4+10;
// char s[maxn];
// set<char>ss;

// int main()
// {
//     ss.clear();
//     scanf("%s",s+1);
//     int len=strlen(s+1),free=0;
//     if (len<26) {puts("-1"); return 0;}
//     rep1(i,1,26)
//         if (s[i]>='A' && s[i]<='Z') ss.insert(s[i]); else free++;
//     int p=26;
//     while (p<=len && ss.size()+free!=26)
//     {
//         p++;
//         if (s[p-26]!='?') ss.erase(s[p-26]); else free--; 
//         if (s[p]!='?') ss.insert(s[p]); else free++;
//     }
//     if (p>26) puts("-1");
//     else
//     {
//         rep1(i,1,p-26)
//             if (s[i]!='?') printf("%c",s[i]); else printf("A");
//         rep1(i,p-25,p) 
//             if (s[i]!='?') printf("%c",s[i]);
//             else 
//             {
//                 int k=65;
//                 while (ss.count((char)k)) k++;
//                 ss.insert((char)k);
//                 printf("%c",(char)k);
//             }
//         rep1(i,p+1,len) 
//             if (s[i]!='?') printf("%c",s[i]); else printf("A");
//         puts("");
//     }
//     return 0;
// }

char s[50010];
int b[27];

int main()
{
    while(scanf("%s",s)!=EOF)
    {
            int flag=true;
            int len=strlen(s);
            if(len<26)
            {
                printf("-1\n");
                continue;
            }
            memset(b,0,sizeof(b));
            for(int i=0;i<=len-26;i++){
                memset(b,0,sizeof(b));
                int cnt1=0,cnt2=0;
                for(int j=i;j<i+26;j++){
                    if(s[j]>='A' && s[j]<='Z'){
                       b[s[j]-'A']++;
                       }
                    else cnt2++;
                }
                for(int j=0;j<26;j++)
                    if(b[j]==1) cnt1++;
                if(cnt2+cnt1 == 26)
                {
                    int t=0;
                    for(int j=i;j<i+26;j++){
                        if(s[j]=='?')
                            {
                                for(;t<26;t++){
                                    if(b[t]==0){
                                        s[j]='A'+t;
                                        t++;
                                        break;
                                    }
                                }
                            }
                    }
                    flag=false;
                }
            }
            for(int i=0;i<len;i++){
                if(s[i]=='?')
                    s[i]='Z';
            }
            if(flag==true) printf("-1\n");
            else printf("%s\n",s);
        }
    return 0;
}