/* Contest xuzhou_2019_online
 * Problem M
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string a, b;
    vector <int> pos[26];
    cin >> n >> m;
    cin >> a >> b;
    int ptr = 0;
    // record position of each letter
    for (unsigned int i = 0; i < a.length(); i++) {
        pos[a[i] - 'a'].emplace_back(i);
    }
    int ans = -1;
    // for each letter in target string
    for (unsigned int i = 0; i < b.length(); i++) {
        int cur = b[i] - 'a';
        // try to find the same letter (cur)
        auto self = lower_bound(pos[cur].begin(), pos[cur].end(), ptr);
        for (int nxt = cur + 1; nxt < 26; nxt++) {
            auto upgrade = lower_bound(pos[nxt].begin(), pos[nxt].end(), ptr);
            if (upgrade != pos[nxt].end()) {
                auto p = *upgrade;
                ans = max(ans, (int) (i + a.length() - p));
            }
        }
        if (self != pos[cur].end()) {
            // found the letter, continue
            ptr = *self + 1; // take *self, go on
            if (i + 1 == b.length()) {
                ans = max(ans, (int) (i + a.length() - ptr + 1));
                if (ans == b.length()) {
                    ans = -1;
                }
            }
        } else {
            // not found
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

// [abcd]
//  0123