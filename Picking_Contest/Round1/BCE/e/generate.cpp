#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    for(int T=1;T<=15;T++){
        string fi="";
		if(T<=9)fi=T+'0';
		else fi=(T/10+'0'),fi+=T%10+'0';
        fi+=".in";
        printf("%s\n",fi.c_str());
        auto in=fopen(fi.c_str(),"w");
        int t=1e4;
        fprintf(in,"%d\n",t);

        while(t--){
            st:
            int h=rand()%100+1;
            int w=rand()%100+1;
            int a=rand()%100+1;
            int b=rand()%100+1;
            int c=rand()%100+1;

            if(a+b+c-max(a,max(b,c))>max(a,max(b,c))){
                fprintf(in,"%d %d %d %d %d\n",h,w,a,b,c);
            }
            else goto st;
        }
    }
}