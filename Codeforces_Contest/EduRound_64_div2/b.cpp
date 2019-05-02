#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2 + 10;

void print(char *a, int len)
{
    for (int i = 1; i <= len; i++) printf("%c", a[i]);
}

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        char s[maxn], a[maxn], b[maxn];
        scanf("%s", s + 1); int len = strlen(s + 1), p = 0, q = 0;
        sort(s + 1, s + 1 + len);
        for (int i = 1; i <= len; i++)
                if (s[i] & 1) a[++p] = s[i]; else b[++q] = s[i];
        if (!p || !q)
        {
            print(a, p); print(b, q);
        }
        else if (abs(a[p] - b[1]) != 1)
        {
            print(a, p); print(b, q);
        }
        else if (abs(b[q] - a[1]) != 1)
        {
            print(b, q); print(a, p);
        }
        else printf("No answer");
        puts("");
    }
    return 0;
}

