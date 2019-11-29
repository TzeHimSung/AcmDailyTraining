#include <iostream>
using namespace std;
struct node{
    int l,r,lc,rc;
    long long c,a,t,ca,at,cat;
};
struct segment_tree{
    static const int N=2000000;
    static const int root=0;
    int num;    
    node tr[2*N];

    void init(int l,int r,int now=root){
        num=0;
        build(l,r,now);
    }
    void build(int l,int r,int now){
        tr[now].l=l; tr[now].r=r; tr[now].c=tr[now].a=tr[now].t=tr[now].ca=tr[now].at=tr[now].cat=0;
        if (l<r){
            int mid=(l+r)>>1;
            ++num; tr[now].lc=num;
            ++num; tr[now].rc=num;
            build(l,mid,tr[now].lc);
            build(mid+1,r,tr[now].rc);
        }
    }
    
    inline void pushup(node &f,const node &lc,const node &rc){
        f.c=lc.c+rc.c;
        f.a=lc.a+rc.a;
        f.t=lc.t+rc.t;
        f.ca=lc.c*rc.a+lc.ca+rc.ca;
        f.at=lc.a*rc.t+lc.at+rc.at;
        f.cat=lc.c*rc.at+lc.ca*rc.t+lc.cat+rc.cat;
    }

    //warning: don't invoke both update and updateR in single segment tree, it may cause error
    void update(int pos,char val,int now=root){
        int mid=(tr[now].l+tr[now].r)>>1;
        if (tr[now].l==tr[now].r) {
            if (val=='C') tr[now].c=1;
            else if (val=='A') tr[now].a=1;
            else tr[now].t=1;
            return;
        } else if (pos<=mid) update(pos,val,tr[now].lc);
        else update(pos,val,tr[now].rc);
        //write parent update here
        pushup(tr[now],tr[tr[now].lc],tr[tr[now].rc]);
    }
    node query(int l,int r,int now=root){
        if (tr[now].l==l && tr[now].r==r) return tr[now];
        else {
            int mid=(tr[now].l+tr[now].r)>>1;
            if (r<=mid) return query(l,r,tr[now].lc);
            else if (l>mid) return query(l,r,tr[now].rc);
            else{
                node ret;
                pushup(ret,query(l,mid,tr[now].lc),query(mid+1,r,tr[now].rc));
                return ret;
            }
        }
    }

};
segment_tree tr;
char str[2000001];
int main(){
    int len,m;

    scanf("%d%d",&len,&m);
    scanf("%s",str);

    tr.init(1,len);
    for (int i=0;i<len;++i)
        tr.update(i+1,str[i]);

    while (m--){
        int l,r;
        scanf("%d%d",&l,&r);
        auto ans=tr.query(l,r);
        printf("%lld\n",ans.cat);
    }
}
