#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("3.in","r",stdin);
    //freopen("3.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            for(int j=0,k=i;j<n;j++,k++){
                if(k>n)k-=n;
                cout<<j*n+k<<" \n"[j==n-1];
            }
    }
}