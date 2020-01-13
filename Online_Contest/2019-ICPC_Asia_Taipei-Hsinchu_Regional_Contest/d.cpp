#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

char s[100];
char a[] = {" bubble"}, b[] = {" tapioka"};
int main() {
    int output = 0;
    while (~scanf("%s", s + 1)) {
        int n = strlen(s + 1);
        if (n == 6) {
            for (int i = 1; i <= 6; i++)if (a[i] != s[i]) {
                    printf("%s ", s + 1); output++; break;
                }
        } else if (n == 7) {
            for (int i = 1; i <= 7; i++)if (b[i] != s[i]) {
                    printf("%s ", s + 1); output++; break;
                }
        } else {
            printf("%s ", s + 1); output++;
        }
    }
    if (!output)printf("nothing\n");
}