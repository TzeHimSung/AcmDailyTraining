#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;

string r90(string rect)
{
    string ret = rect;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ret[j * N + N - 1 - i] = rect[i * N + j];
        }
    }
    return ret;
}
string r180(string rect)
{
    return (r90(r90(rect)));
}
string r270(string rect)
{
    return r90(r90(r90(rect)));
}
string fz(string rect)
{
    string ret = rect;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ret[i * N + j] = rect[i * N + (N - j - 1)];
        }
    }
    return ret;
}
int main()
{
    string str, end;
    cin >> N;
    string tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        str += tmp;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        end += tmp;
    }
    if (r90(str) == end)
        cout << 1;
    else if (r180(str) == end)
        cout << 2;
    else if (r270(str) == end)
        cout << 3;
    else if ((tmp = fz(str)) == end)
        cout << 4;
    else if (r90(tmp) == end || r180(tmp) == end || r270(tmp) == end)
        cout << 5;
    else if (str == end)
        cout << 6;
    else
        cout << 7;
    return 0;
}