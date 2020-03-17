class Solution {
public:
    int countCharacters(vector<string> &words, string chars) {
        map<char, int>cntSource;
        for (auto ch : chars) cntSource[ch]++;

        function<bool(string)> check = [&](string word)->bool {
            map<char, int>cnt = cntSource;

            for (auto w : word) {
                if (cnt[w]) cnt[w]--;
                else return false;
            }

            return true;
        };

        int ret = 0;
        for (auto word : words) {
            if (check(word)) {
                ret += word.size();
            }
        }
        return ret;
    }
};