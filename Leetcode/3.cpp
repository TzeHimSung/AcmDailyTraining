class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size(), ans = 0;
        map<char, int>m;
        m.clear();
        for (int i = 0, j = 0; j < len; j++) {
            if (m.count(s[j]))
                i = max(i, m[s[j]]);
            ans = max(ans, j - i + 1);
            m[s[j]] = j + 1;
        }
        return ans;
    }
};