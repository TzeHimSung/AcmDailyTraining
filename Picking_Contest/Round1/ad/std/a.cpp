#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct record{
    int n,m,id;
    record(){}
    record(int _n,int _m,int _id){
        n=_n; m=_m; id=_id;
    }
    bool operator < (const record &b) const{
        if (n!=b.n) return n>b.n;
        return m<b.m;
    }
};
vector<record> records;
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        int n;
        scanf("%d",&n);
        records.clear();
        for (int i=0;i<n;++i) {
            int n,m;
            scanf("%d%d",&n,&m);
            records.push_back(record(n,m,i+1));
        }
        sort(records.begin(),records.end());
        for (int i=0;i<n;++i) printf("%d ",records[i].id);
        printf("\n");
    }
}
