#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    int boy = 0, girl = 0;
    for (int i = 0;i < s.size() - 2;i++) {
        if (s[i] == 'b' && s[i + 1] == 'o' && s[i + 2] == 'y') {
            s[i] = s[i + 1] = s[i + 2] = '.';
            boy++;
        }
    }
    for (int i = 0;i < s.size() - 3;i++) {
        if (s[i] == 'g' && s[i + 1] == 'i' && s[i + 2] == 'r' && s[i + 3] == 'l') {
            s[i] = s[i + 1] = s[i + 2] = s[i + 3] = '.';
            girl++;
        }
    }
    set<char>sboy{ 'b', 'o', 'y' }, sgirl{ 'g','i','r', 'l' };
    map<char, char>mboy, mgirl;
    mboy['b'] = '?', mboy['o'] = 'b', mboy['y'] = 'o';
    mgirl['g'] = '?', mgirl['i'] = 'g', mgirl['r'] = 'i', mgirl['l'] = 'r';
    for (int i = 0;i < s.size();i++) {
        if (sboy.find(s[i]) != sboy.end() && (i - 1 < 0 || s[i - 1] != mboy[s[i]])) boy++;
        if (sgirl.find(s[i]) != sgirl.end() && (i - 1 < 0 || s[i - 1] != mgirl[s[i]])) girl++;
    }
    cout << boy << '\n' << girl << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}