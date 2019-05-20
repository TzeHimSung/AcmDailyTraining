#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int v1 = 0, v2 = 0;
    for(int i = 0; i < n / 2; i++)
        v1 += s[i] - 'A', v2 += s[i + n / 2] - 'A';
    v1 %= 26; v2 %= 26;
    for(int i = 0; i < n / 2; i++)
    {
        int v = (((s[i] - 'A' + v1) + (s[i + n / 2] - 'A' + v2)) % 26 + 26);
        putchar(v % 26 + 'A');
    }
}