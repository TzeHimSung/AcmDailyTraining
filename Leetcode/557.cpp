class Solution {
public:
    string reverseWords(string s) {
        string ret = "", tmp = "";
        for (auto i : s) {
            if (i != ' ') tmp += i;
            else {
                reverse(tmp.begin(), tmp.end());
                ret += tmp + ' ';
                tmp = "";
            }
        }
        reverse(tmp.begin(), tmp.end());
        ret += tmp;
        return ret;
    }
};
