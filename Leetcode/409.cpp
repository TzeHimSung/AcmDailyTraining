class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>m;
        for (auto ch : s) m[ch]++;
        int ans = 0;
        for (auto i : m) {
            ans += i.second % 2 == 0 ? i.second : i.second - 1;
        }
        return ans < s.size() ? ans + 1 : ans;
    }
};