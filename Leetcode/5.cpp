class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0, start = 0, end = 0, startPos = 0, len = 0, n = s.size();
        while (i < n) {
            start = end = i;
            while (i + 1 < n && s[end] == s[end + 1]) end++;
            i = end + 1;
            while (start - 1 >= 0 && end + 1 < n && s[start - 1] == s[end + 1]) {
                start--, end++;
            }
            if (len < end - start + 1) {
                len = end - start + 1;
                startPos = start;
            }
        }
        return s.substr(startPos, len);
    }
};