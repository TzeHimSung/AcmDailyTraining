/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int t;

string solve(string s) {
    string ans = "", tmp = "";
    vector<string>vec;
    vec.clear();
    for (auto i : s) {
        if (i != ':') tmp += i;
        else {
            vec.push_back(tmp);
            tmp = "";
        }
    }
    vec.push_back(tmp);
    if (s[0] == s[1] && s[1] == ':') {
        ans += "0000";
        for (int i = 1; i <= 8 - vec.size() + 1; i++) ans += ":0000";
        for (int i = 2; i < vec.size(); i++) {
            if (i) ans += ":";
            if (vec[i].size() != 4) {
                for (int j = 1; j <= 4 - vec[i].size(); j++) ans += "0";
            }
            ans += vec[i];
        }
    } else if (s[s.size() - 2] == s[s.size() - 1] && s[s.size() - 1] == ':') {
        for (int i = 0; i < vec.size() - 2; i++) {
            if (i) ans += ":";
            if (vec[i].size() != 4) {
                for (int j = 1; j <= 4 - vec[i].size(); j++) ans += "0";
            }
            ans += vec[i];
        }
        for (int i = 1; i <= 8 - vec.size() + 2; i++) ans += ":0000";
    } else {
        bool printed = false;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].size()) {
                if (i) ans = ans + ":";
                if (vec[i].size() != 4) {
                    for (int j = 1; j <= 4 - vec[i].size(); j++) ans += "0";
                }
                // cout << vec[i];
                ans += vec[i];
            } else {
                if (printed) continue;
                printed = true;
                for (int j = 1; j <= 8 - vec.size() + 1; j++) ans += ":0000";
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        string s; cin >> s;
        if (s == "::") cout << "0000:0000:0000:0000:0000:0000:0000:0000" << endl;
        else cout << solve(s) << endl;
    }
    return 0;
}