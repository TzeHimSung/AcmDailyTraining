/* Nowcoder Contest 887
 * Problem A
 * Au: SJoshua
 */
#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPerfect(string str) {
    // cout << "judge " << str << endl;
    string mk = str + str;
    vector <string> strs;
    strs.push_back(str);
    for (int i = 1; i < str.length(); i++) {
        string s = mk.substr(i, str.length());
        strs.push_back(s);
        if (s == str) {
            break;
        }
    }
    sort(strs.begin(), strs.end());
    return *strs.begin() == str;
}

string concat(vector <string> list, string con) {
    string ret = list[0];
    for (auto i = 1; i < list.size(); i++) {
        ret += con;
        ret += list[i];
    }
    return ret;
}

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        string input, cur, str, head, tail, tmp;
        vector <string> ans;
        cin >> input;
        int left = 0, right = 0;
        for (left = 0; left < input.length() && input[left] == '1'; left++);
        for (right = input.length() - 1; right >= 0 && input[right] == '0'; right--);
        for (int i = 0; i < left; i++) head += input[i];
        for (int i = left; i <= right; i++) str += input[i];
        for (int i = right + 1; i < input.length(); i++) tail += input[i];
        int readingOne = false;
        if (!head.empty()) {
            ans.push_back(head);
        }

        vector <string> bits;
        for (auto ch : str) {
            if (ch == '0') {
                if (readingOne) {
                    bits.push_back(tmp);
                    tmp.clear();
                    readingOne = false;
                }
            } else if (ch == '1') {
                if (!readingOne) {
                    readingOne = true;
                }
            }
            tmp += ch;
        }
        bits.push_back(tmp);

        int cnt = 0;
        while (cnt < bits.size()) {
            for (int i = bits.size() - 1; i >= cnt; i--) {
                string tst;
                for (int j = cnt; j <= i; j++) {
                    tst += bits[j];
                }
                if (isPerfect(tst)) {
                    if (!tst.empty()) ans.push_back(tst);
                    cnt = i + 1;
                }
            }
        }

        if (!tail.empty()) {
            ans.push_back(tail);
        }
        cout << concat(ans, " ") << endl;
    }
    return 0;
}