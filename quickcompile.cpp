/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int main(int args, char **argv) {
    string fileName = "";
    int len = strlen(argv[args - 1]);
    for (int i = 0; i < len; i++) {
        if (argv[args - 1][i] == '.') break;
        else fileName += argv[args - 1][i];
    }
    if (fileName == "com") {
        puts("File name is empty!");
        return 0;
    }
    printf("Compile %s.cpp with GNU g++ 9.1.0\n", fileName.c_str());
    string command = "g++ -g " + fileName + ".cpp -o " + fileName + ".out -std=c++14 -O2 -Wall";
    printf("Command: %s\n", command.c_str());
    system(command.c_str());
    return 0;
}