#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, s;
    scanf("%d %d", &n, &s);
    int maxi = 0;
    while (n--)
    {
        int t;
        scanf("%d", &t);
        maxi = max(maxi, t);
    }
    printf("%d\n", (maxi * s + 999) / 1000);
    return 0;
}