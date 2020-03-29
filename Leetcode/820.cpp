class Solution {
public:
    int minimumLengthEncoding(vector<string> &words) {
        for (auto &word : words) {
            reverse(word.begin(), word.end());
        }
        sort(words.begin(), words.end());
        int ret = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            int size = words[i].size();
            if (words[i] == words[i + 1].substr(0, size)) continue;
            ret += size + 1;
        }
        return ret + words.back().size() + 1;
    }
};
