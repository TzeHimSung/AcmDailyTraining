class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if ((int)haystack.size() < (int)needle.size()) return -1;
        map<char, int>pos;
        for (int i = 0; i < needle.size(); i++) {
            pos[needle[i]] = needle.size() - i;
        }

        function<int(string, string)> sunday = [&](string s, string t)->int{
            int i = 0;
            while (i <= s.size() - t.size()) {
                int j = 0;
                // 开始匹配
                while (s[i + j] == t[j]) {
                    j++;
                    // 匹配成功
                    if (j == t.size()) return i;
                }
                // 匹配失败
                // 不存在的情况
                if (i + t.size() == s.size()) return -1;
                // 决定怎么跳
                if (pos.count(s[i + t.size()])) {
                    i += pos[s[i + t.size()]];
                } else {
                    i += t.size() + 1;
                }
            }
            return -1;
        };

        return sunday(haystack, needle);
    }
};